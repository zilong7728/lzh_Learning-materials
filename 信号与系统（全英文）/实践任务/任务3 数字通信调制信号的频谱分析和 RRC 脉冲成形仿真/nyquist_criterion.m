%奈奎斯特准则

Fs = 10^9;    % 采样频率                    
T = 1/Fs;    %采样周期       
L = 48;    %信号长度
t = (0:L-1)*T;    %时间

%生成三个滚降系数不同的升余弦函数
h_1 = rcosdesign(0.25,6,4);    %滚降系数为0.25
fvtool(h_1,'Analysis','impulse');
h_2 = rcosdesign(0.5,6,4);    %滚降系数为0.5
fvtool(h_2,'Analysis','impulse');
h_3 = rcosdesign(1,6,4);    %滚降系数为1
fvtool(h_3,'Analysis','impulse');

%画h_1的频谱
Y_1 = fft(h_1);
P2_1 = abs(Y_1/L);
P1_1 = P2_1(1:L/2+1);
P1_1(2:end-1) = 2*P1_1(2:end-1);
f = Fs*(0:(L/2))/L;
plot(f,P1_1) 
title('Single-Sided Amplitude Spectrum of X(t)')
xlabel('f (Hz)')
hold on

%画h_2的频谱
Y_2 = fft(h_2);
P2_2 = abs(Y_2/L);
P1_2 = P2_2(1:L/2+1);
P1_2(2:end-1) = 2*P1_2(2:end-1);
f = Fs*(0:(L/2))/L;
plot(f,P1_2) 
title('Single-Sided Amplitude Spectrum of X(t)')
xlabel('f (Hz)')
hold on

%画h_3的频谱
Y_3 = fft(h_3);
P2_3 = abs(Y_3/L);
P1_3 = P2_3(1:L/2+1);
P1_3(2:end-1) = 2*P1_3(2:end-1);
f = Fs*(0:(L/2))/L;
plot(f,P1_3) 
title('Single-Sided Amplitude Spectrum of X(t)')
xlabel('f (Hz)')
ylabel('|P(f)|')
hold on
