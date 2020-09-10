y = audioread('Q2.wav'); % 单声道语音信号保存在向量 y 里
Fs = 44.1e+3; % 语音信号的采样率，44.1kHz
audiowrite('t1.wav',y,Fs);
sound(y,Fs);
pause

y_reverse = y(length(y):-1:1); % 语音信号的时间反演
audiowrite('t2.wav',y_reverse,Fs);
sound(y_reverse,Fs); 
pause

y_compress = y(1:2:length(y)); % 语音信号的时间压缩
audiowrite('t3.wav',y_compress,Fs);
sound(y_compress,Fs);
pause

y_extend = zeros(1,2*length(y));
y_extend(1:2:2*length(y)) = y;
y_extend(2:2:2*length(y)) = y; % 语音信号的时间拓展
audiowrite('t4.wav',y_extend,Fs);
sound(y_extend,Fs);
