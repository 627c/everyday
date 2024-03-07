%二分法求方程近似根 自动化2301 刘安琪

%变量的定义
a=0;
b=1;
f=@(x)exp(x)+10*x-2;
e=0.5*10^(-6);        %误差限
N=50;                 %最大二分次数
fprintf('k\ta\t\t\tb\t\t\tx\t\t\tb-a\n')
for k=1:1:N
    x=(a+b)/2;
    fprintf('%d\t%.6f\t%.6f\t%.6f\t%.8f\n',k,a,b,x,b-a);
    %判断中点值是否为0
    if f(x)==0
        fprintf('找到近似根x=%.6f,二分次数k=%d\n',x,k);
        break;
    end
    %调整区间端点值
    if f(a)*f(x)<0
        b=x;
    else
        a=x;
    end
    %判断是否满足误差条件并输出最终结果
    if abs(b-a)<e
        fprintf('找到近似根x=%.6f,二分次数k=%d,误差=%.8f\n',x,k,b-a);
        break;
    end
end
if k>N
    fprintf('二分失败');
end
