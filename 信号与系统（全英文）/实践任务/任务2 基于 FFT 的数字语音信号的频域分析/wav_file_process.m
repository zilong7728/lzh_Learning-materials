%读取音频文件'Государственный гимн СССР.wav'
[xx,fs] = audioread('Государственный гимн СССР.wav'); %xx为读出的数据，Fs为音频文件本身的采样率

%单独取出读到的数据，并计算数据个数和信号持续时间
x = xx(:, 1);
N = length(x);    %数据个数
time = (0 : N-1) / fs;    %信号持续时间

%画出读到的数据
plot(x);

%对信号进行fft
M = 204800;
nfft = 819200;    %由采样定理得到的采样率
window = hanning(M);    %加窗（汉宁窗），目的是采样保持
freq = (0 : nfft/2) * fs /nfft;
y = x(9001 : 9000+M);
y = y - mean(y);
Y = fft(y .* window, nfft);

%画图
subplot 211;
plot(y);
xlim([0 M]);
title('信号波形');
xlabel('样点');
ylabel('幅值');

subplot 212;
plot(freq,20*log10(abs(Y(1:nfft/2+1))));
grid;
axis([0 max(freq) -60 55]);
title('频谱');
xlabel('频率(Hz)');
ylabel('幅值dB')
