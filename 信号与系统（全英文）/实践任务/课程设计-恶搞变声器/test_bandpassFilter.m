%读取声音文件
[sound0,fs] = audioread('woman.wav');
sound1=sound0(:,1);

%带通滤波
sound2=filter(Num,1,sound1); %Num为由filter designer生成的一个滤波器序列
sound(sound2,fs);
filename=('test_bandpassFilter.wav');
audiowrite(filename,sound2,fs);