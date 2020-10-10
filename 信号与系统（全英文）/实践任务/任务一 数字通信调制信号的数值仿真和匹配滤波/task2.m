%假设信号为4-QAM信号
%经过计算可以得到Eb=1,故N0=1/10，方差=N0/2=1/20
%在第一题产生的信号中加入高斯白噪声
%画图时将不需要画的部分注释化即可

signal_In=randsrc(128,2);    %生成一个128*2的矩阵，代表长度为128的随机信号In（包括实部和虚部）
signal_In_noisy=awgn(signal_In,10);    %在生成的信号中加入高斯白噪声，SNR=10

%s(t)的实部信号加白噪声画图
real_part=0;    %初始化信号的实部
time=0:0.1:129;    %设置t的取值范围从0到129，步长为0.1
t01=0;  %设定t0为阶跃点
t02 = t01 + 1;
g=stepfun(time,t01)-stepfun(time,t02);  %生成g(t)函数
for i=1:128
    real_part=real_part+signal_In_noisy(i,1)*(stepfun(time,t01+i)-stepfun(time,t02+i));   %实部作累加
    plot(real_part,'-+r');   %画出实部
    hold on    %不清除画板，准备继续画虚部
end

%s(t)的虚部信号加白噪声画图
imagine_part=0;    %初始化信号的虚部
time=0:0.1:129;    %设置t的取值范围从0到129，步长为0.1
t01=0;  %设定t0为阶跃点
t02 = t01 + 1;
g=stepfun(time,t01)-stepfun(time,t02);  %生成g(t)函数
for i=1:128
    imagine_part=imagine_part+signal_In_noisy(i,2)*(stepfun(time,t01+i)-stepfun(time,t02+i));    %虚部作累加
    %plot(imagine_part,'-*b');    %画出虚部
    hold on    %不清除画板
end

%s(t)实部信号的白噪声画图
real_part=0;    %初始化信号的实部
time=0:0.1:129;    %设置t的取值范围从0到129，步长为0.1
t01=0;  %设定t0为阶跃点
t02 = t01 + 1;
g=stepfun(time,t01)-stepfun(time,t02);  %生成g(t)函数
for i=1:128
    real_part=real_part+(signal_In_noisy(i,1)-signal_In(i,1))*(stepfun(time,t01+i)-stepfun(time,t02+i));   %实部噪声作累加
    plot(real_part,'-+y');   %画出实部噪声
    hold on    %不清除画板，准备继续画虚部
end

%s(t)虚部信号的白噪声画图
imagine_part=0;    %初始化信号的虚部
time=0:0.1:129;    %设置t的取值范围从0到129，步长为0.1
t01=0;  %设定t0为阶跃点
t02 = t01 + 1;
g=stepfun(time,t01)-stepfun(time,t02);  %生成g(t)函数
for i=1:128
    imagine_part=imagine_part+signal_In_noisy(i,2)*(stepfun(time,t01+i)-stepfun(time,t02+i));    %虚部噪声作累加
    %plot(imagine_part,'-*k');    %画出虚部噪声
    hold on    %不清除画板
end
