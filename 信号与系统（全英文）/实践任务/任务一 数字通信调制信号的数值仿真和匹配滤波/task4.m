%4QAM，格雷衍射
nuber_symbol = 10000;    %一共有1万个符号用于测试
M = 4;    %阶数，表示4QAM
graycode = [0 1 2 3];    %格雷映射，十进制表示
SNR = -20:1:20;    %符号比，单位db,设置步长为1，
ebn0 = 10 .^ (SNR / 10);    %将db转为非线性的方式
msg = randi([0,3], 1, nuber_symbol);    %随机产生0-3的符号，乘nsymbol得到原始数据
msg1 = graycode(msg+1);    %格雷映射
msgmod = qammod(msg1,M);    %调用qammod函数，得到调制后的符号
spow = norm(msgmod) .^2 / nuber_symbol;    %a+bj取模的平方，即功率；功率除以整个符号得到平均功率
for i = 1:length(SNR)
    sigma = sqrt(spow / (2*ebn0(i))); 
    rx = msgmod + sigma * (randn(1, length(msgmod)) + 1i * randn(1, length(msgmod)));    %星座点图乘以随机长度高斯白噪声
    y = qamdemod(rx,M);    %转为对应的点
    decmsg = graycode(y + 1);    %格雷逆映射
    [err, ser(i)] = symerr(msg, decmsg);    %比较符号误差
end

p_4QAM = 2 * (1 - 0.5 .* qfunc(sqrt(2 * ebn0))) .* qfunc(sqrt(2 * ebn0));    %误码率
ser1 = p_4QAM;

figure()
semilogy(SNR, ser, '*', SNR, ser1, '-');    %ser实际错误概率，ser1理论符号错误概率
title('4QAM-AWGN符号错误概率分析')
xlabel('SNR');
ylabel('概率');
legend('仿真值','理论值' );


%16QAM
nuber_symbol = 10000;    %一共有1万个符号用于测试
M = 16;    %阶数，表示16QAM
graycode = [0 1 3 2 4 5 7 6 12 13 15 14 8 9 11 10];    %格雷映射，十进制表示
SNR = -20:1:20;    %符号比，单位db,设置步长为1，由于semilogy函数的限制，将12改为20
ebn0 = 10 .^ (SNR / 10);    %将db转为非线性的方式
msg = randi([0,15], 1, nuber_symbol);    %随机产生0-15的符号，乘nsymbol得到原始数据
msg1 = graycode(msg + 1);    %格雷映射
msgmod = qammod(msg1, M);    %调用qammod函数，得到调制后的符号
spow = norm(msgmod) .^2 / nuber_symbol;    %a+bj取模的平方，即功率；功率除以整个符号得到平均功率
for i = 1:length(SNR)
    sigma = sqrt(spow / (2 * ebn0(i)));
    rx = msgmod + sigma * (randn(1, length(msgmod)) + 1i * randn(1, length(msgmod)));    %星座点图乘以随机长度高斯白噪声
    y = qamdemod(rx, M);    %转为对应的点
    decmsg = graycode(y + 1);    %格雷逆映射
    [err,ser(i)] = symerr(msg, decmsg);    %比较符号误差
end

p_16QAM = 2 * (1 - 1 / sqrt(M)) * qfunc(sqrt(3 * ebn0 / (M - 1)));    %理论误码率
ser1 = 1 - (1 - p_16QAM) .^2;

figure()
semilogy( SNR,ser,'*',SNR,ser1,'-');    %ser实际错误概率，ser1理论符号错误概率
title('16QAM-AWGN符号错误概率分析')
xlabel('SNR');
ylabel('概率');
legend('仿真值','理论值' );
