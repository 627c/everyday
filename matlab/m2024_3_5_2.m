%迭代法求方程实根
g=@(x)(x+1)^(1/6);
x0=1.5;
k=1;
x=g(x0);
while abs(x-x0)>=0.0005
    x0=x;
    x=g(x0);
    k=k+1;
    if k>50
        fprintf('迭代失败');
        break;
    end
end
fprintf('%d\n',k);
fprintf('%.3f',x);