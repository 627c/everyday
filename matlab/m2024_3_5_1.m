%二分法求方程实根
f=@(x)x^6-x-1;
a=1;
b=2;
k=1;
x=(a+b)/2;
if f(x)==0
    fprintf('%d\n',k);
    fprintf('%.3f',x);
else
    if f(a)*f(x)<0
        b=x;
    else
        a=x;
    end
end
while abs(b-a)>=0.0005 %精确到小数后三位
    x=(a+b)/2;
    if f(x)==0
        fprintf('%d\n',k);
        fprintf('%.3f',x);
    else
        if f(a)*f(x)<0
            b=x;
        else
            a=x;
        end
    end
    k=k+1;
    if k>50
        break;
    end
end
fprintf('%d\n',k);
fprintf('%.3f',x);




