%读取女声文件
[sound0,fs]=audioread('woman.wav');
sound1=sound0(:,1);
len=length(sound1);
len2=len*2-1;
sound2=zeros(len2,1);

%插值
for i=1:len2
    if(mod(i,2)<1)
        sound2(i)=(sound1(fix(i/2))+sound1(fix(i/2)+1))/2;
    else
        sound2(i)=sound1(fix((i+1)/2));
    end
end

%汉宁窗
win=hanning(1024,'periodic');
for i=1:len2
    sound2(i)=sound2(i)*win(mod(i-1,1024)+1);
end

%TSM
sound3=zeros(len,1);
for i=1:512
    sound3(i)=sound2(i);
end
m=512;
for i=513:len
    sound3(i)=sound2(i+m)+sound2(i+m-512);
    if(mod(i,512)==0)
        m=m+512;
    end
end

%发声并输出
sound(sound3,fs)
filename=('test_hanningWindow.wav');
audiowrite(filename,sound3,fs);

%显示频谱

sound1_fft=fft(sound1);
abs_sound1_fft=abs(sound1_fft);

sound3_fft=fft(sound3);
abs_sound3_fft=abs(sound3_fft);

s=linspace(0,fs,len+1);
x=s(1:len);
subplot (2,1,1);
semilogx(x,abs_sound1_fft);
xlim([20,20000]);
title('原音频频谱');
xlabel('Frequency/Hz');
ylabel('Amplitude');

subplot (2,1,2);
semilogx(x,abs_sound3_fft);
xlim([20,20000]);
title('变声后频谱');
xlabel('Frequency/Hz');
ylabel('Amplitude');