%part1: 画出新的卷积后加噪声的信号
signal_In_part_1=randsrc(128,2);     %储存In

t = 0:0.01:129;    %g(t)的时间长短
t_1 = 0:0.01:2*129;    %卷积需要的时间长短
w = 1;    %tripuls(t, w, s)函数的参数：三角波的宽度w
tfutr = 0.5;
sfutr = 1;    %tripuls(t, w, s)函数的参数，三角波的最大值出现在(w * s) / 2处
g_real=0;    %初始化g()的实部为0
g_imagine=0;    %初始化g()的虚部为0
h = tripuls(-t+0.5,w,sfutr);    %生成新的脉冲信号g(t)

%生成g(t)函数
for i = 1:128
    g_real = g_real + signal_In_part_1(i, 1) * tripuls(t-tfutr-i+1, w, sfutr);
    g_imagine = g_imagine + signal_In_part_1(i, 2) * tripuls(t-tfutr-i+1, w, sfutr);
end 

%加入高斯白噪声
y_real = awgn(g_real, 10, 'measured');
y_imagine = awgn(g_imagine, 10, 'measured');

%卷积
z_real = conv(g_real+y_real, h);
z_imagine = conv(g_imagine+y_imagine, h);
plot(t_1, z_real, 'blue');
hold on
plot(t_1, z_imagine, 'red');



%part2: 4QAM信号
for SNR = -20:1:30
    count=0; 
    
signal_In_part_2 = randsrc(128,2);    %储存In
signal_In_part_2_noisy = rand(128,2);    %初始化还原信号
t01 = 0;    %设定t0为阶跃点
t02 = t01 + 1;
t = 0:0.01:129;
t2 = 0:0.01:258;
w = 1;

%生成新g(t)，方法与part1相同
tfutr = 0.5;
sfutr = 1;
g_real = 0;
g_imagine=0;
h = tripuls(-t+0.5, w, sfutr);   %新的h(t)

%生成g(t)
for i = 1:128
    g_real = g_real + signal_In_part_2(i, 1) * tripuls(t-tfutr-i+1, w, sfutr);
    g_imagine = g_imagine + signal_In_part_2(i, 2) * tripuls(t-tfutr-i+1, w, sfutr);
end

%加入高斯白噪声
y_real = awgn(g_real, SNR);
y_imagine = awgn(g_imagine, SNR);

%卷积
z_real = conv(g_real+y_real, h);%z是新的r(t)
z_imagine = conv(g_imagine+y_imagine, h);

%信号的采样
for j = 1:128
   temp1 = (z_real(1, 10 * j) - 1) ^2 + (z_imagine(1, 10 * j) - 1) ^2;    %计算到1+j距离
   temp2 = (z_real(1, 10 * j) - 1) ^2 + (z_imagine(1, 10 * j) + 1) ^2;    %计算到1-j距离
   temp3 = (z_real(1, 10 * j) + 1) ^2 + (z_imagine(1, 10 * j) - 1) ^2;    %计算到-1+j距离
   temp4 = (z_real(1, 10 * j) + 1) ^2 + (z_imagine(1, 10 * j) + 1) ^2;    %计算到-1-j距离
   temp=[temp1 temp2 temp3 temp4];
   w=min(temp);
   if w==temp1
      signal_In_part_2_noisy(j,1) =1;
      signal_In_part_2_noisy(j,2) =1;
   end
   if w==temp2
      signal_In_part_2_noisy(j,1) =1;
      signal_In_part_2_noisy(j,2) =-1;           
   end
   if w==temp3
      signal_In_part_2_noisy(j,1) =-1;
      signal_In_part_2_noisy(j,2) =1; 
   end
   if w==temp4
      signal_In_part_2_noisy(j,1) =-1;
      signal_In_part_2_noisy(j,2) =-1; 
   end
end

for i = 1:128
   if (signal_In_part_2(i, 1) ~= signal_In_part_2_noisy(i, 1)) || (signal_In_part_2(i, 2) ~= signal_In_part_2_noisy(i, 2))
      count=count+1;  
   end  
end

%输出
p=count/128.0;
%plot(SNR,p,'red');
%hold on
plot(SNR,p);
%ber仿真值，ser比特仿真值，ber1理论误比特率，ser1理论误码率
semilogy(SNR,p,'o' );
title('4QAM-AWGN 新信号的符号错误率');
xlabel('SNR');
ylabel('probability');
legend('符号仿真');
hold on
end



%加入采样错误
for SNR = -20:1:30
    count=0; 
    
signal_In_part_2 = randsrc(128,2);  %储存In
signal_In_part_2_noisy = rand(128,2);  %初始化还原信号
t01 = 0;    %设定t0为阶跃点
t02 =t01 + 1;
t = 0:0.1:129;
t2 = 0:0.1:258;
w = 1;

%生成g(t)
tfutr = 0.5;
sfutr = 1;
g_real = 0;
g_imagine = 0;
h = tripuls(-t + 0.5, w, sfutr);    %新的h(t)

%生成g(t)函数
for i = 1:128
   g_real = g_real + signal_In_part_2(i, 1) * tripuls(t-tfutr-i+1, w, sfutr);
   g_imagine = g_imagine + signal_In_part_2(i, 2) * tripuls(t-tfutr-i+1, w, sfutr);
end

%加入高斯白噪声
y_real = awgn(g_real, SNR);
y_imagine = awgn(g_imagine, SNR);

%卷积
z_real = conv(g_real + y_real, h);    %z是新的r(t)信号
z_imagine = conv(g_imagine + y_imagine, h);    %z是新的r(t)信号
for j = 1:128    %信号的采样
   temp1 = (z_real(1, 10 * j + randsrc(1, 1, [-2 -1 0 1 2])) - 1) ^2 + (z_imagine(1, 10 * j + randsrc(1, 1, [-2 -1 0 1 2])) - 1) ^2;   %计算到1+j距离
   temp2 = (z_real(1, 10 * j + randsrc(1, 1, [-2 -1 0 1 2])) - 1) ^2 + (z_imagine(1, 10 * j + randsrc(1, 1, [-2 -1 0 1 2])) + 1) ^2;   %计算到1-j距离
   temp3 = (z_real(1, 10 * j + randsrc(1, 1, [-2 -1 0 1 2])) + 1) ^2 + (z_imagine(1, 10 * j + randsrc(1, 1, [-2 -1 0 1 2])) - 1) ^2;   %计算到-1+j距离
   temp4 = (z_real(1, 10 * j + randsrc(1, 1, [-2 -1 0 1 2])) + 1) ^2 + (z_imagine(1, 10 * j + randsrc(1, 1, [-2 -1 0 1 2])) + 1) ^2;   %计算到-1-j距离
   temp = [temp1 temp2 temp3 temp4];
   w = min(temp);
   if w == temp1
      signal_In_part_2_noisy(j, 1) = 1;
      signal_In_part_2_noisy(j, 2) = 1;
   end
   if w == temp2
      signal_In_part_2_noisy(j, 1) = 1;
      signal_In_part_2_noisy(j, 2) = -1;           
   end
   if w == temp3
      signal_In_part_2_noisy(j, 1) = -1;
      signal_In_part_2_noisy(j, 2) = 1; 
   end
   if w == temp4
      signal_In_part_2_noisy(j, 1) = -1;
      signal_In_part_2_noisy(j, 2) = -1; 
   end
end

for i = 1:128
   if (signal_In_part_2(i, 1) ~= signal_In_part_2_noisy(i, 1)) || (signal_In_part_2(i, 2) ~= signal_In_part_2_noisy(i, 2))
      count=count+1;  
   end  
end

%输出
p = count / 128.0;
%plot(SNR,p,'red');
%hold on
plot(SNR, p);
%ber仿真值，ser比特仿真值，ber1理论误比特率，ser1理论误码率
semilogy(SNR,p,'o' );
title('4QAM-AWGN 新信号的符号错误率加入采样错误')
xlabel('SNR');ylabel('probability');
legend('符号仿真');
hold on
end