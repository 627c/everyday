%简单迭代法求方程近似根 自动化2301 刘安琪
%变量的定义
x0=0;
e=0.5*10^(-6);
N=50;           %最大迭代次数
g=@(x)(2-exp(x))/10;    %迭代函数
fprintf('k\tx\tx-x0\n');
%迭代过程
for k=1:1:N
    x=g(x0);
    fprintf('%d\t%.6f\t%.8f\n',k,x,x-x0);
    %判断是否满足误差条件并输出最终结果
    if abs(x-x0)<e
        fprintf('迭代次数k=%d,迭代值x=%.6f,迭代误差=%.8f\n',k,x,x-x0);
        break;
    end
    
    x0=x;
end
if k>N
    fprintf('迭代失败');
end
