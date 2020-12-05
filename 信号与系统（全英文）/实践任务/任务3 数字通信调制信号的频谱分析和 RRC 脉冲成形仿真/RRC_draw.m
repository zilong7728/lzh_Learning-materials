%画频谱
%主要思路与任务一中的思路相同，这里只是把方波载波变成了RRC脉冲

%产生RRC脉冲
h_1 = rcosdesign(0.25,40,60);
M = 16;%更改参数决定是4QAM还是14QAM的信号
h_1_origin = h_1;  %保存下原始的gt信号
fs = 10^10;

%新建一个空的一维数组，可以容纳1000*2401个元素，用于构建冲激串
chain_rcosdesign=zeros(1,58345);
for i= 0:1:999
    for j=1:1:2401
      chain_rcosdesign(i*56+j)=chain_rcosdesign(i*56+j)+h_1(j);                 
    end
end
%构建好了类似于冲激串的函数,但是需要对于信号进行四舍五入，否则无法使用qammod函数
chain_rcosdesign=round(chain_rcosdesign);
st = qammod( chain_rcosdesign,M);
L_1=length(st);  %信号的总时长
L_2=length(h_1_origin);
Sf=fft(st);
y_SF=(abs(Sf)).^2;
f_1=(0:L_1-1)*fs/L_1;

%画出|S( f )|^2
figure(1)
plot(f_1,y_SF) 
title('double-Sided Amplitude Spectrum of X(t)')
xlabel('f (Hz)')
ylabel('|S(f)|^2')

%画出Phi_s
figure(2)
Gf=fft(h_1_origin);
y_phiF=(10^10)*(abs(Gf)).^2;
f_2=(0:L_2-1)*fs/L_2;
plot(f_2,y_phiF) 
title('double-Sided Amplitude Spectrum of X(t)')
xlabel('f (Hz)')
ylabel('phi(f)')
