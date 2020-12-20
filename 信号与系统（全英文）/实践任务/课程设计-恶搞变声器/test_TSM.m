%用TSM缩短时长——变速不变调
%使用重叠叠加OLA

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

%TSM
sound3=zeros(len,1);
m=0;
for i=1:len
    sound3(i)=sound2(i+m)+sound2(i+m-512);
    if(mod(i,512)==0)
        m=m+512;
    end
end

%平滑
for i=1:len-50
    if(mod(i,512)==0)
        p=(sound3(i)-sound3(i+50))/50;
        for j=1:50
            sound3(j+i)=sound3(i)-j*p;
        end
    end
end

sound(sound3,fs)
filename=('test_TSM_linear_connect.wav');
audiowrite(filename,sound2,fs);