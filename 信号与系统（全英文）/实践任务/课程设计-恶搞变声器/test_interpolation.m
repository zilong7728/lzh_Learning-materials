%利用插值的方法改变基频变声——女变男

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

sound(sound2,fs);
filename=('test_interpolation.wav');
audiowrite(filename,sound2,fs);