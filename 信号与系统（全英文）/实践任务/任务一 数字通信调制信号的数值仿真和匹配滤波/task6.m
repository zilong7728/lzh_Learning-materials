%格雷映射
nsymbol= 10000;%一共有1万个符号
M=16;%阶数，表示16QAM
graycode=[0 1 3 2 4 5 7 6 12 13 15 14 8 9 11 10];%格雷映射，十进制表示
SNR=5:20;%符号比，单位db
esn0=10.^(SNR/10);%将db转为非线性的方式
msg=randi([0,15],1,nsymbol);%随机产生0-15的符号，乘nsymbol得到原始数据
msg1=graycode(msg+1);%格雷映射
msgmod=qammod(msg1,M);%调用qammod函数，得到调制后的符号
spow=norm(msgmod).^2/nsymbol;%a+bj取模的平方，功率；功率除以整个符号得到平均功率
for i= 1:length(SNR)
    sigma=sqrt(spow/(2*esn0(i))); 
    rx=msgmod+sigma*(randn(1,length(msgmod))+1i*randn(1,length(msgmod))); %星座点图乘以随机长度高斯白噪声
    y=qamdemod(rx,M);%转为对应的点
    decmsg=graycode(y+1);%格雷逆映射
    [err1 ,ber(i)]=biterr(msg,decmsg,log2(M));
    [err2,ser(i)]=symerr(msg,decmsg);%比较符号误差
end

p16=2*(1-1/sqrt(M))*qfunc(sqrt(3*esn0/(M-1)));%误码率
ser1=1-(1-p16).^2;
ber1=1/log2(M)*ser1;%误比特率
figure()
%ber仿真值，ser比特仿真值，ber1理论误比特率，ser1理论误码率
semilogy(SNR,ber,'o' ,SNR,ser,'*',SNR,ser1,'-',SNR,ber1,'-.');
title('16QAM-AWGN比特错误率与符号错误率格雷映射')
xlabel('SNR');ylabel('probability');
legend('比特仿真','符号仿真','理论误比特率' ,'理论符号错误率');


%自然映射，仿真结果

a=sqrt(1/10);

%随机生成4000个0/1作为初始信号
raw=rand(1,4000);
s=round(raw);

%分成4列
B = reshape(s,4,1000);
C = B;
B1 = B(1,:);
B2 = B(2,:);
B3 = B(3,:);
B4 = B(4,:);
            %M=16;%阶数，表示16QAM
            %esn0=10.^(snrdb/10);
%在这里我们仍然借用格雷映射的调制公式
%但在调制前将不同的码位置换掉
for i=1:1000
    if B1(i)==0 && B2(i)==0 && B3(i)==1 && B4(i)==0
        B4(i)=1;
    end
    if B1(i)==0 && B2(i)==0 && B3(i)==1 && B4(i)==1
        B4(i)=0;
    end
    if B1(i)==1 && B2(i)==0 && B3(i)==1 && B4(i)==1
        B4(i)=0;
    end
    if B1(i)==1 && B2(i)==0 && B3(i)==1 && B4(i)==0
        B4(i)=1;
    end
    if B1(i)==1 && B2(i)==1 && B3(i)==1 && B4(i)==1
        B4(i)=0;
    end
    if B1(i)==1 && B2(i)==1 && B3(i)==1 && B4(i)==0
        B4(i)=1;
    end
    if B1(i)==0 && B2(i)==1 && B3(i)==1 && B4(i)==1
        B4(i)=0;
    end
    if B1(i)==0 && B2(i)==1 && B3(i)==1 && B4(i)==0
        B4(i)=1;
    end
end

%根据星座图调制信号
tx = a*(-2*(B3-0.5).*(3-2*B4)-j*2*(B1-0.5).*(3-2*B2));

for snrdb = 1:1:20
    
    %向信号中加入噪声
    rx = awgn(tx,snrdb);
    
    %解调信号
    B5 = imag(rx)<0;
    B6 = (imag(rx)<2*a) & (imag(rx)>-2*a);
    B7 = real(rx)<0;
    B8 = (real(rx)<2*a) & (real(rx)>-2*a);
    
    %解调后还原信号
    for i=1:1000
    if B5(i)==0 && B6(i)==0 && B7(i)==1 && B8(i)==0
        B4(i)=1;
    end
    if B5(i)==0 && B6(i)==0 && B7(i)==1 && B8(i)==1
        B4(i)=0;
    end
    if B5(i)==1 && B6(i)==0 && B7(i)==1 && B8(i)==1
        B8(i)=0;
    end
    if B5(i)==1 && B6(i)==0 && B7(i)==1 && B8(i)==0
        B8(i)=1;
    end
    if B5(i)==1 && B6(i)==1 && B7(i)==1 && B8(i)==1
        B8(i)=0;
    end
    if B5(i)==1 && B6(i)==1 && B7(i)==1 && B8(i)==0
        B8(i)=1;
    end
    if B5(i)==0 && B6(i)==1 && B7(i)==1 && B8(i)==1
        B8(i)=0;
    end
    if B5(i)==0 && B6(i)==1 && B7(i)==1 && B8(i)==0
        B8(i)=1;
    end
    end
    
    rs = [B5;B6;B7;B8];
    
    %计算BER
    error = rs~=C;
    BER(snrdb) = sum(sum(error)) / 4000;
end
            %p16=2*(1-1/sqrt(M))*qfunc(sqrt(3*esn0/(M-1)));%误码率
            %ser1=1-(1-p16).^2;
            %ber1=1/log2(M)*ser1;%误比特率
snrdb = 1:1:20;
figure()
semilogy(snrdb,BER,'o');
title('16QAM-AWGN比特错误率自然映射');
xlabel('SNR');
ylabel('probability');

%自然映射，理论值
a=sqrt(1/10);

%随机生成4000个0/1作为初始信号
raw=rand(1,4000);
s=round(raw);

%分成4列
B = reshape(s,4,1000);
C = B;
B1 = B(1,:);
B2 = B(2,:);
B3 = B(3,:);
B4 = B(4,:);
            M=16;%阶数，表示16QAM
            esn0=10.^(snrdb/10);
%在这里我们仍然借用格雷映射的调制公式,在调制前将不同的码位置换掉

for i=1:1000
    if B1(i)==0 && B2(i)==0 && B3(i)==1 && B4(i)==0
        B4(i)=1;
    end
    if B1(i)==0 && B2(i)==0 && B3(i)==1 && B4(i)==1
        B4(i)=0;
    end
    if B1(i)==1 && B2(i)==0 && B3(i)==1 && B4(i)==1
        B4(i)=0;
    end
    if B1(i)==1 && B2(i)==0 && B3(i)==1 && B4(i)==0
        B4(i)=1;
    end
    if B1(i)==1 && B2(i)==1 && B3(i)==1 && B4(i)==1
        B4(i)=0;
    end
    if B1(i)==1 && B2(i)==1 && B3(i)==1 && B4(i)==0
        B4(i)=1;
    end
    if B1(i)==0 && B2(i)==1 && B3(i)==1 && B4(i)==1
        B4(i)=0;
    end
    if B1(i)==0 && B2(i)==1 && B3(i)==1 && B4(i)==0
        B4(i)=1;
    end
end

%根据星座图调制信号
tx = a*(-2*(B3-0.5).*(3-2*B4)-j*2*(B1-0.5).*(3-2*B2));

for snrdb = 1:1:20
    
    %向信号中加入噪声
    rx = awgn(tx,snrdb);
    
    %解调信号
    B5 = imag(rx)<0;
    B6 = (imag(rx)<2*a) & (imag(rx)>-2*a);
    B7 = real(rx)<0;
    B8 = (real(rx)<2*a) & (real(rx)>-2*a);
    
    %解调后还原信号
    for i=1:1000
    if B5(i)==0 && B6(i)==0 && B7(i)==1 && B8(i)==0
        B4(i)=1;
    end
    if B5(i)==0 && B6(i)==0 && B7(i)==1 && B8(i)==1
        B4(i)=0;
    end
    if B5(i)==1 && B6(i)==0 && B7(i)==1 && B8(i)==1
        B8(i)=0;
    end
    if B5(i)==1 && B6(i)==0 && B7(i)==1 && B8(i)==0
        B8(i)=1;
    end
    if B5(i)==1 && B6(i)==1 && B7(i)==1 && B8(i)==1
        B8(i)=0;
    end
    if B5(i)==1 && B6(i)==1 && B7(i)==1 && B8(i)==0
        B8(i)=1;
    end
    if B5(i)==0 && B6(i)==1 && B7(i)==1 && B8(i)==1
        B8(i)=0;
    end
    if B5(i)==0 && B6(i)==1 && B7(i)==1 && B8(i)==0
        B8(i)=1;
    end
    end
    
    rs = [B5;B6;B7;B8];
    
    %计算BER
    error = rs~=C;
    BER(snrdb) = sum(sum(error)) / 4000;
end
            p16=2*(1-1/sqrt(M))*qfunc(sqrt(3*esn0/(M-1)));%误码率
            ser1=1-(1-p16).^2;
            ber1=1/log2(M)*ser1;%误比特率
snrdb = 1:1:20;
figure()
semilogy(snrdb,ber1,'-');
title('16QAM-AWGN比特错误率自然映射');
xlabel('SNR');
ylabel('probability');