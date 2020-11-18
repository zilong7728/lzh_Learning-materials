function[Xk]=my_fft(Xn,N)    %函数：快速傅里叶变换，传入数列Xn和长度N

    %如果没有输入N，将N记为Xn的长度
    if nargin < 2
        N = length(Xn);
    end

    %如果传入的N大于Xn的长度，Xn补零（0不影响fft的结果）
    Xn = [Xn, zeros(1, N-length(Xn))];

    %计算蝶形运算的级数M
    tempbinary = dec2bin(N);    %将数字转换为二进制数
    M = length(tempbinary(2:end));  %级数M就是二进制数的位数
    tempdata = zeros(N, M+1);   %中间操作存储矩阵

    %对输入进行排序
    for n = 0 : N-1
        tempbinary = dec2bin(n, M);
        tempbinary = rot90(tempbinary, 2);    
        tempdata(n+1, 1) = Xn(bin2dec(tempbinary)+1); %数组都从1开始计数
    end

    %开始fft
    for m = 0 : M-1
    %产生W     
        for r = 1 : 2^m
            W(r) = cos((pi / 2^m) * (r - 1)) - 1j * sin((pi / 2^m) * (r - 1));  %W数组从1开始存数
        end
        for i = 1 : r
            for groupseq = 1 : N/(2^(m+1))
                p = i + (groupseq - 1) * 2^(m + 1); %用组号和W因子号确定P的坐标
                q = p + 2^m;
                tempdata(p, m+2) = tempdata(p, m+1) + W(i) * tempdata(q, m+1); %计算蝶形单元
                tempdata(q, m+2) = tempdata(p, m+1) - W(i) * tempdata(q, m+1); 
            end
        end
    end

    Xk = tempdata(:, M+1);
    m = size(Xk);
    m1 = size(Xn);
    if m ~= m1
        Xk = Xk';
    end
end