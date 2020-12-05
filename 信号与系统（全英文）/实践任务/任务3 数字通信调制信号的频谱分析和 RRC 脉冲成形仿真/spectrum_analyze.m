%数字调制信号的频谱分析

fs = 10^10;
t = -10^-6:1/fs:10^-6;
w = 10^-9;
delay = 0.5 * w;

%产生矩形脉冲
gt = rectpuls(t-delay,w);
M = 16; %填4或16来选择4-QAM或16-QAM
gt_original = gt;  %存储下原始的脉冲信号
st = qammod(gt,M);

%产生冲激串信号
for i = 1:1:999
    st=st+qammod(rectpuls(t-delay-i*w,w),M);  
end
L_1 = length(st);  %信号的总时长
L_2 = length(gt_original);
Sf = fft(st);
y_SF = (abs(Sf)).^2;
f_1 = (0:L_1-1)*fs/L_1;

%画出|S( f )|^2
figure(1)
plot(f_1,y_SF) 
xlabel('f (Hz)')
ylabel('|S(f)|^2')

%画出Phi(f)
Gf = fft(gt_original);
y_PhiF = (10^10)*(abs(Gf)).^2;
f_2 = (0:L_2-1)*fs/L_2;
figure(2)
plot(f_2,y_PhiF) 
xlabel('f (Hz)')
ylabel('phi(f)')
