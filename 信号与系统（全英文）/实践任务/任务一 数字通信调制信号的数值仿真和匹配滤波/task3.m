% part1: 画出g(t)经过匹配滤波器后的输出信号
t_part_1 = 0:0.001:10;  %设置t的取值范围从0到10，步长为0.001

t01_part_1 = 0;    %设定t0为阶跃点
t02_part_1 = t01_part_1 + 1;
g_part_1 = stepfun(t_part_1, t01_part_1) - stepfun(t_part_1, t02_part_1);     %生成g(t)函数

z_part_1 = conv(g_part_1, g_part_1);    %在该问题中g(t)和h(t)为同一个函数，所以卷积可以写成这个形式
%plot(z_part_1);    %画出g(t)与h(t)卷积的图



% part2: 画出匹配滤波后的信号（含有高斯白噪声）
signal_In = randsrc(128, 2);    %生成一个128*2的矩阵，代表长度为128的随机信号In（包括实部和虚部）

t = 0:0.1:129;    %设置步长为0.1
t0 = 0:0.1:129 * 2;

g = 0;    %将g(t)初始化为0
t01 = 0;    %设定t0为阶跃点
t02 = t01 + 1;
h = stepfun(t, t01) - stepfun(t, t02);    %定义h(t)
for i = 1:128
    g = g + signal_In(i, 1) * (stepfun(t, t01+i) - stepfun(t, t02+i));    %生成g(t)函数
end

y = awgn(g, 10, 'measured');    %添加高斯白噪声

z = conv(g+y, h);    %匹配滤波
plot (t0, z, 'blue');    %画出滤波后的图
hold on