%任务一：随机生成一个 4-QAM 或者 16-QAM 的 In 序列（例如长度为 128 的序列），
%在 MATLAB 中画出对应发送信号 s(t)的实部和虚部信号。
%同时，计算该系统的平均比特能量，和理论计算结果进行对比验证

signal_In=randsrc(128,2);    %生成一个128*2的矩阵，代表长度为128的随机信号In（包括实部和虚部）

%s(t)的实部信号
real_part=0;    %初始化信号的实部
time=0:0.1:129;    %设置t的取值范围从0到129，步长为0.1
t01=0;  %设定t0为阶跃点
t02 = t01 + 1;
g=stepfun(time,t01)-stepfun(time,t02);  %生成g(t)函数
for i=1:128
    real_part=real_part+signal_In(i,1)*(stepfun(time,t01+i)-stepfun(time,t02+i));   %实部作累加
    plot(real_part,'-+r');   %画出实部
    hold on    %不清除画板，准备继续画虚部
end

%s(t)的虚部信号
imagine_part=0;    %初始化信号的虚部
time=0:0.1:129;    %设置t的取值范围从0到129，步长为0.1
t01=0;  %设定t0为阶跃点
t02 = t01 + 1;
g=stepfun(time,t01)-stepfun(time,t02);  %生成g(t)函数
for i=1:128
    imagine_part=imagine_part+signal_In(i,2)*(stepfun(time,t01+i)-stepfun(time,t02+i));    %虚部作累加
    plot(imagine_part,'-*b');    %画出虚部
    hold on    %不清除画板
end

%经过理论计算，平均比特能量是1
%实际计算为2*128/2*128=1