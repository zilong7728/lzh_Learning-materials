clear all;
close all;
clc;

% rand('seed',0);
% 可以设置随机数种子，同一个随机数种子下的随机数序列相同

%%
dct_size = 8;                                       % DCT点数
sort_size = 16;                                     % 排序数量
test_times = 3;                                     % 生成几组随机数
signal = zeros(test_times, dct_size);               % 用于dct变换的随机信号
signal_dct = zeros(test_times, dct_size);           % 完成dct变换的信号
signal_dct_matlab = zeros(test_times, dct_size);    % 完成dct变换的信号
num = zeros(test_times, sort_size);                 % 排序前的序列
num_sort = zeros(test_times, sort_size);            % 排序后的序列


%%
% 产生随机数据
for times = 1 : test_times
    % 生成随机信号
    rand_num = 2 * rand(1, dct_size) - 1;
    signal(times, : ) = floor(rand_num * 2^15 + 0.5) / 2^15;
    
    % 生成随机乱序序列
    rand_num = 2 * rand(1, sort_size) - 1;
    num(times, : ) = floor(rand_num * 2^15);
end

%%
% 生成DCT变换矩阵
dct_mat = zeros(dct_size);
for u = 1 : dct_size
    for i = 1 : dct_size
        if u == 1
            Au = (1 / dct_size)^0.5;
        else
            Au = (2 / dct_size)^0.5;
        end
        dct_mat(u, i) = Au * cos((i - 0.5) * pi * (u - 1) / dct_size);
    end
end
dct_mat = floor(dct_mat * 2^12 + 0.5) / 2^12;

%%
% DCT变换
% 变换的矩阵将直接给出，地址为0-63，即(u, i)的地址为（u - 1）*8 + (i - 1)
% 定点方案为S(16, 12)，即一共16位位宽，12位小数位宽
% 由于这些系数不会超过1，所以可以理解为(-1, 1 - 2^(-12)]

% 输入的信号的地址为64-71，暂定定点方案为S(16, 15)，即[-1, 1 - 2^(-15)]
% 但不管怎么变化都一定是16位的定点数

% 16位*16位=32位，保证乘法不会溢出，实际上变换矩阵不会超过1，所以有效位数只有29位
% 之后会进行8次相加，最多增加3位，保证加法不会溢出
for times = 1 : test_times
    for u = 1 : dct_size
        for i = 1 : dct_size
            signal_dct(times, u) = signal_dct(times, u) + signal(times, i) * dct_mat(u, i); 
        end
    end
end
% matlab的DCT变换，用于对比正确性
for times = 1 : test_times
    signal_dct_matlab(times, :) = dct2(signal(times, : ));
end

%%
% 排序
num_min_1 = 0;
num_min_2 = 0;
pos_min_1 = 0;
for times = 1 : test_times
    % 先判定最开始的两个数
    temp1 = abs(num(times, 1));
    temp2 = abs(num(times, 2));
    if temp1 > temp2
        num_min_1 = temp2;
        num_min_2 = temp1;
        pos_min_1 = 2;
    else
        num_min_1 = temp1;
        num_min_2 = temp2;
        pos_min_1 = 1;
    end
    % 循环更新
    for i = 3 : sort_size
        temp1 = abs(num(times, i));
        if temp1 < num_min_2
            if temp1 < num_min_1
                num_min_2 = num_min_1;
                num_min_1 = temp1;
                pos_min_1 = i;
            else
                num_min_2 = temp1;
            end
        end
    end
    % 输出结果
    for i = 1 : sort_size
        if i == pos_min_1
            num_sort(times, i) = num_min_2;
        else
            num_sort(times, i) = num_min_1;
        end
    end
end

%%
% 输出结果
fprintf('\nDCT变换矩阵十进制结果：\n');
for u = 1 : dct_size
    for i = 1 : dct_size
        fprintf('%10f ', dct_mat(u, i));
    end
    fprintf('\n');
end

fprintf('\nDCT变换矩阵十六进制结果：\n');
dct_mat_hex = dct_mat * 2^12;
% 小数无法直接转换为十六进制数，因此先要将其换算为整数，后面同理
dct_mat_hex(find(dct_mat_hex < 0)) = dct_mat_hex(find(dct_mat_hex < 0))+ 2^32;
% dec2hex无法转换负数，因此对于负数需要先转换为二进制相同的正数，后面同理
for u = 1 : dct_size
    for i = 1 : dct_size
        fprintf('%08s ', dec2hex(dct_mat_hex(u, i)));
    end
    fprintf('\n');
end

fprintf('\nDCT变换前十进制结果：\n');
for times = 1 : test_times
    fprintf('%10f ', signal(times, :));
    fprintf('\n');
end

fprintf('\nDCT变换后十进制结果：\n');
for times = 1 : test_times
    fprintf('%10f ', signal_dct(times, :));
    fprintf('\n');
end

fprintf('\nDCT变换后matlab结果：\n');
for times = 1 : test_times
    fprintf('%10f ', signal_dct_matlab(times, :));
    fprintf('\n');
end

fprintf('\nDCT变换前十六进制结果：\n');
signal_hex = signal * 2^15;
signal_hex(find(signal_hex < 0)) = signal_hex(find(signal_hex < 0))+ 2^32;
for times = 1 : test_times
    for i = 1 : dct_size
        fprintf('%08s ', dec2hex(signal_hex(times, i)));
    end
    fprintf('\n');
end

fprintf('\nDCT变换后十六进制结果：\n');
signal_dct_hex = signal_dct * 2^31;
signal_dct_hex(find(signal_dct_hex < 0)) = signal_dct_hex(find(signal_dct_hex < 0))+ 2^32;
for times = 1 : test_times
    for i = 1 : dct_size
        fprintf('%08s ', dec2hex(signal_dct_hex(times, i)));
    end
    fprintf('\n');
end

fprintf('\n排序前十进制结果：\n');
for times = 1 : test_times
    fprintf('%6d ', num(times, :));
    fprintf('\n');
end

fprintf('\n排序十进制结果：\n');
for times = 1 : test_times
    fprintf('%6d ', num_sort(times, :));
    fprintf('\n');
end

fprintf('\n排序前十六进制结果：\n');
num_hex = num;
num_hex(find(num_hex < 0)) = num_hex(find(num_hex < 0))+ 2^32;
for times = 1 : test_times
    for i = 1 : sort_size
        fprintf('%08s ', dec2hex(num_hex(times, i)));
    end
    fprintf('\n');
end

fprintf('\n排序后十六进制结果：\n');
for times = 1 : test_times
    for i = 1 : sort_size
        fprintf('%08s ', dec2hex(num_sort(times, i)));
    end
    fprintf('\n');
end

%%
% 打印coe文件和txt文件

% 打印DCT的coe和txt文件
sel_print = 1;                  % 选择一组DCT数据打印
f1 = fopen('DCT_input.coe', 'w');
fprintf(f1, 'memory_initialization_radix = 16;\nmemory_initialization_vector = \n');
% DCT的输入的coe文件包含DCT的变换矩阵，地址为0-63
for u = 1 : dct_size
    for i = 1 : dct_size
        fprintf(f1, '%08s,\n', dec2hex(dct_mat_hex(u, i)));
    end
end
% 变换矩阵后接着的为信号数据，地址为64-71
for i = 1 : dct_size
    fprintf(f1, '%08s', dec2hex(signal_hex(sel_print, i)));
    if i < dct_size
        fprintf(f1, ',\n');
    else
        fprintf(f1, ';');
    end
end
fclose(f1);
f1 = fopen('DCT_output.txt', 'w');
for i = 1 : dct_size
    fprintf(f1, '%08s ', dec2hex(signal_dct_hex(sel_print, i)));
end
fclose(f1);

% 打印排序的coe和txt文件
sel_print = 1;                  % 选择一组排序数据打印
f1 = fopen('sort_input.coe', 'w');
fprintf(f1, 'memory_initialization_radix = 16;\nmemory_initialization_vector = \n');
for i = 1 : sort_size
    fprintf(f1, '%08s', dec2hex(num_hex(sel_print, i)));
    if i < sort_size
        fprintf(f1, ',\n');
    else
        fprintf(f1, ';');
    end
end
fclose(f1);

f1 = fopen('sort_output.txt', 'w');
for i = 1 : sort_size
    fprintf(f1, '%08s ', dec2hex(num_sort(sel_print, i)));
end
fclose(f1);

















