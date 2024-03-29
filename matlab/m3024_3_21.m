%三角分解法(Doolittle) 自动化2301 刘安琪
%A,b的定义
A=[1.1348,3.8326,1.1651,3.4017;0.5301,1.7875,2.5330,1.5435;3.4129,4.9317,8.7643,1.3142;1.2371,4.9998,10.6721,0.0147];
b=[9.5342;6.3941;18.4231;16.9237];
%L,U的定义
U=zeros(4,4);
L=eye(4);
%L,U的计算
U(1,:)=A(1,:);              %U的第一行
L(2:4,1)=A(2:4,1)/U(1,1);       %L的第一列
     %第r行/列
for r=2:1:4
    U(r,r:4)=A(r,r:4)-L(r,1:r-1)*U(1:r-1,r:4);
    if r==4
        break;
    end
    L(r+1:4,r)=(A(r+1:4,r)-L(r+1:4,1:r-1)*U(1:r-1,r))/U(r,r);
end
fprintf('系数矩阵A的分解矩阵：\n  单位下三角阵L=\n');
fprintf('%12.4f%12.4f%12.4f%12.4f\n',L(1,:),L(2,:),L(3,:),L(4,:));
fprintf('  上三角阵U=\n');
fprintf('%12.4f%12.4f%12.4f%12.4f\n',U(1,:),U(2,:),U(3,:),U(4,:));
%求解Ly=b,Ux=y公式
y=zeros(4,1);
x=zeros(4,1);
     %求y
y(1)=b(1);
for i=2:1:4
    y(i)=b(i)-L(i,1:i-1)*y(1:i-1);
end
     %求x
x(4)=y(4)/U(4,4);
for i=3:-1:1
    x(i)=(y(i)-U(i,i+1:4)*x(i+1:4))/U(i,i);
end
fprintf('分两步求解得到的方程组的解：\n  Y=\n');
fprintf('%12.4f%12.4f%12.4f%12.4f\n',y(1),y(2),y(3),y(4));
fprintf('  X=\n');
fprintf('%.20f\t%.20f\t%.20f\t%.20f\n',x(1),x(2),x(3),x(4));
