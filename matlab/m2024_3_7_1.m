%二分法
a=0.3;
b=0.4;
e=0.5*10^(-5);
f=@(x)x^4-3*x+1;
N=50;
for k=1:1:N
    x=(a+b)/2;
    if f(x)==0
        fprintf('%.5f',x);
        break;
    end
    if f(a)*f(x)<0
        b=x;
    else
        a=x;
    end
    if abs(b-a)<e
        fprintf('%.5f',x);
        break;
    end
end
if k>50
    fprintf('二分失败');
end
