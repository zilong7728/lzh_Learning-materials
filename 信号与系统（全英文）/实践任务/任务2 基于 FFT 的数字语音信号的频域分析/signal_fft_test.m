fs = 100; %设置采样频率为100
N = 256; %设置数据点数为256

%得到时间序列
n = 0 : N - 1;
t = n / fs;

%待处理信号
x = sin(2 * pi * 10 * t) + 2 * sin(2 * pi * 40 * t);

%对信号进行fft
y = fft(x, N); 

%求fft后的振幅
mag = abs(y); 

%频率序列
f = n * fs / N;

%画振幅-频率图
subplot(2,2,1),plot(f,mag); 
xlabel('频率/Hz');
ylabel('振幅');
title('N=256');
grid on;
