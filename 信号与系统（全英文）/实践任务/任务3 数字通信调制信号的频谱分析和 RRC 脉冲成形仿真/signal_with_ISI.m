clc
clear variables
close all

%% 随机信号的生成
%=====定义待仿真序列的维数
global N
N=10000;
%=====定义产生“1”的概率为p
global p
p=0.5;
%==========================
%首先产生随机二进制序列
source=randsrc(1,N,[1,0;p,1-p]);
%===========================
%画出二进制序列
figure(1)
stem(source(1,1:50),'filled');
title('随机二进制序列');
%=============================
%对产生的二进制序列进行QAM调制
[source1,source2]=Qam_modulation(source);
%=============================
%画出星座图
figure(2)
scatter(source1,source2,'b*');
title('16QAM星座图');
axis([-5 5 -5 5])
%==============================
%对两路信号进行插值
sig_insert1=insert_value(source1,8);
sig_insert2=insert_value(source2,8);
%===============================
%画出插值后两路信号的波形图
figure(3)
subplot(2,1,1);
plot(sig_insert1(1,1:80));
title('插值后两路信号的波形图：实部信号');
subplot(2,1,2);
plot(sig_insert2(1,1:80));
title('插值后两路信号的波形图：虚部信号');
%===============================
%通过低通滤波器
rolloff = 0.25;  % Filter rolloff
span = 6;        % Filter span
sps = 4;         % Samples per symbol
[sig_rcos1,sig_rcos2]=rise_cos(sig_insert1,sig_insert2,rolloff,span,sps);
%===============================
%画出通过低通滤波器的两路波形图
figure(4)
subplot(2,1,1);
plot(sig_rcos1(1,1:80));
title('通过低通滤波器的两路波形图：实部信号');
subplot(2,1,2);
plot(sig_rcos2(1,1:80));
title('通过低通滤波器的两路波形图：虚部信号');
%=================================
%10倍载波调制
[t,sig_modulate]=modulate_to_high(sig_rcos1,sig_rcos2,0.25,2);
%=================================
%画出传输的实信号图形
figure(5)
plot(t(1:500),sig_modulate(1:500));
title('传输的实信号图形');
%=================================
%将滤波后的信号加入高斯白噪声
snr=10;
[x1,x2]=generate_noise(sig_rcos1,sig_rcos2,snr);
sig_noise1=x1.';
sig_noise2=x2.';
%=================================
%画出加入高斯白噪声的波形
figure(6)
subplot(2,1,1);
plot(sig_noise1(1:80));
title('加入高斯白噪声的信号波形:实部信号');
subplot(2,1,2);
plot(sig_noise2(1:80));
title('加入高斯白噪声的信号波形:虚部信号');
%==================================
%经过匹配滤波器
[sig_match1,sig_match2]=filt_match(sig_noise1,sig_noise2,rolloff,span,sps);
%===============================
%画出通过匹配滤波器的两路波形图
figure(7)
subplot(2,1,1);
plot(sig_match1(1:80));
title('通过匹配滤波器的两路波形图：实部信号');
subplot(2,1,2);
plot(sig_match2(1:80));
title('通过匹配滤波器的两路波形图：虚部信号');
%================================
%采样
% sample=8;
[x1,x2]=pick_sig(sig_match1,sig_match2,8);
sig_pick1=x1.';
sig_pick2=x2.';
%================================
%画出采样后的星座图
figure(8)
scatter(sig_pick1,sig_pick2,'b*');
title('采样后的16QAM星座图');
axis([-5 5 -5 5])
%=================================
%解调
signal=demodulate_sig(sig_pick1,sig_pick2);
%================================
%画出解调后的二进制信号
figure(9)
stem(signal(1,1:50));
title('解调后的二进制信号');
% %计算误bit率
% error_b=length(find(signal~=source))/N;


%% 误码率计算
% =======理论误bit率
snr=1:1:11;
error_theory=(1-(1-(2*(1-1/sqrt(16))*1/2*erfc(1/sqrt(2)*sqrt(3*4*10.^(snr/10)/(16-1))))).^2)/4;
% =======用理论的误bit率来决定需要仿真的点数
n=floor(1./error_theory)*1000+100;
n(n<5000)=5000;
% 开始仿真
for i=1:length(n)
% 首先产生随机二进制序列
source=randsrc(1,n(i),[1,0;p,1-p]);    
% 对产生的二进制序列进行QAM调制
[source1,source2]=Qam_modulation(source);
% 对两路信号进行插值
sig_insert1=insert_value(source1,8);
sig_insert2=insert_value(source2,8);
% 通过低通滤波器
rolloff = 0.25;  % Filter rolloff
span = 6;        % Filter span
sps = 4;         % Samples per symbol
[sig_rcos1,sig_rcos2]=rise_cos(sig_insert1,sig_insert2,rolloff,span,sps);
% 将滤波后的信号加入高斯白噪声
[x1,x2]=generate_noise(sig_rcos1,sig_rcos2,snr(i));
sig_noise1=x1.';
sig_noise2=x2.';
% 经过匹配滤波器
[sig_match1,sig_match2]=filt_match(sig_noise1,sig_noise2,rolloff,span,sps);
% 采样
[x1,x2]=pick_sig(sig_match1,sig_match2,8);
sig_pick1=x1.';
sig_pick2=x2.';
% 解调
signal=demodulate_sig(sig_pick1,sig_pick2);
% 计算误bit率
error_bit(i)=length(find(signal-source)~=0)/n(i);
end
figure(10)
semilogy(snr,error_theory,'r-');
hold on
semilogy(snr,error_bit,'b-');
xlabel('信噪比SNR')
ylabel('误bit率')
title('理论误比特率与仿真误比特率')
legend('理论误比特率','仿真误比特率')


%% 星座图映射
function[y1,y2]=Qam_modulation(x)
%Qam_modulation
%===================================
%对产生的二进制序列进行QAM调制
    %=======首先进行串并转换，将原二进制序列转换成两路信号
N=length(x);
a=1:2:N;
y1=x(a);
y2=x(a+1);
    %=======分别对两路信号进行16QAM调制
        %======对两路信号进行2-4电平变换
a=1:2:N/2;
temp1=y1(a);
temp2=y1(a+1);
y11=temp1*2+temp2;

temp1=y2(a);
temp2=y2(a+1);
y22=temp1*2+temp2;
        %======对两路信号分别进行相位调制
a=1:N/4;
y1=(y11*2-1-4)*1.*cos(2*pi*a);
y2=(y22*2-1-4)*1.*cos(2*pi*a);
        %======按照格雷码的规则进行映射
y1(y11==0)=-3;
y1(y11==1)=-1;
y1(y11==2)=3;
y1(y11==3)=1;

y2(y22==0)=-3;
y2(y22==1)=-1;
y2(y22==2)=3;
y2(y22==3)=1;
end

%% 插值
function y=insert_value(x,ratio)
%============================
%=======x是待插值序列，ratio是插值比例
%=======两路信号进行插值
%=======首先产生一个长度等于ratio倍原信号长度的零向量
y=zeros(1,ratio*length(x));
%========再把信号放在对应的位置
a=1:ratio:length(y);
y(a)=x;
end

%% 波形成型
%=========x1、x2是两路输入信号
function[y1,y2]=rise_cos(x1,x2,rolloff,span,sps)
%========生成平方根升余弦滤波器
rrcFilter=rcosdesign(rolloff,span,sps,'sqrt');
%=======对两路信号进行滤波
y1=upfirdn(x1,rrcFilter,sps);
y2=upfirdn(x2,rrcFilter,sps);
end

%% 10倍载波调制
%=====x1，x2代表两路输入信号，f是输入信号的频率，hf是载波频率
function [t,y]=modulate_to_high(x1,x2,f,hf)
%=====产生两个中间变量，用来存储插值后的输入信号
yo1=zeros(1,length(x1)*hf/f*10);
yo2=zeros(1,length(x2)*hf/f*10);
n=1:length(yo1);
%=======对输入信号分别进行插值，相邻的两个点之间加入9个点，且这9个点的值同第0个点的值
yo1(n)=x1(floor((n-1)/(hf/f*10))+1);
yo2(n)=x2(floor((n-1)/(hf/f*10))+1);
%======生成输出信号的时间向量
t=(1:length(yo1))/hf*f/10;
%======生成载波调制信号
y=yo1.*cos(2*pi*hf*t)-yo2.*sin(2*pi*hf*t);
end

%% 加入高斯白噪声
%======对输入的两路信号加高斯白噪声，返回处理后的两路信号，信息点等效bit信噪比为snr的值
function[y1,y2]=generate_noise(x1,x2,snr)
%=======snr1代表snr对于的符号信噪比
snr1=snr+10*log10(4);
%=======算出所有信号的平均功率
ss=var(x1+1i*x2,1);
%=======加入高斯白噪声
y=awgn(x1+1i*x2,snr1+10*log10(ss/10),'measured');
y1=real(y);
y2=imag(y);
end

%% 匹配滤波器
%=========x1、x2是两路输入信号
function[y1,y2]=filt_match(x1,x2,rolloff,span,sps)
%========生成平方根升余弦滤波器
rrcFilter=rcosdesign(rolloff,span,sps,'sqrt');
%=======对两路信号进行滤波
y1=upfirdn(x1,rrcFilter,1,sps);
y2=upfirdn(x2,rrcFilter,1,sps);
end


%% 采样
function[y1,y2]=pick_sig(x1,x2,ratio)
y1=x1(3*2+1:ratio:length(x1)-ratio);
y2=x2(3*2+1:ratio:length(x2)-ratio);
end

%% 判决解调
function y=demodulate_sig(x1,x2)
%=======对x1路信号进行判决
xx1(x1>2)=3;
xx1((x1<2)&(x1>=0))=1;
xx1((x1>=-2)&(x1<0))=-1;
xx1(x1<-2)=-3;
%=======对x2路信号进行判决
xx2(x2>2)=3;
xx2((x2<2)&(x2>=0))=1;
xx2((x2>=-2)&(x2<0))=-1;
xx2(x2<-2)=-3;
%========将x1路信号按格雷码规则还原成0,1信号
temp1=zeros(1,length(xx1)*2);
temp1(find(xx1==-1)*2)=1;
temp1(find(xx1==1)*2-1)=1;
temp1(find(xx1==1)*2)=1;
temp1(find(xx1==3)*2-1)=1;
%========将x2路信号按格雷码规则还原成0,1信号
temp2=zeros(1,length(xx2)*2);
temp2(find(xx2==-1)*2)=1;
temp2(find(xx2==1)*2-1)=1;
temp2(find(xx2==1)*2)=1;
temp2(find(xx2==3)*2-1)=1;
%========将两路信号合成1路
y=zeros(1,length(temp1)*2);
y(1:2:length(y))=temp1;
y(2:2:length(y))=temp2;
end
