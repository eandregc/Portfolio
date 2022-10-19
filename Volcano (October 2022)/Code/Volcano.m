%Proyecto Volcan
%Creado por Andre González id:A01741225
%Gianni Freire id:A00835838
%Diego Fernando Sabillon id:A01798446
%Nicolás Mendoza Peña id:A00835649

%Iniciales
vo=(input('Velocidad Inicial: ')); %Vo
a=(input('Angulo: ')); %Angulo
diametro=(input('Diametro: ')); %Diametro
m=(input('Masa: ')); %Masa

%Calculos Constantes
g=-9.81; %Gravedad
d=0.166; %Delta
x=0; %PosicionInicialX
y=0; %PosicionInicialY
z=0; %PosicionInicialZ
B=0.00016; %b
b=diametro*B; %b
vx=vo*cos(a); %VelocidadInicialEnX
vy=vo*sin(a); %VelocidadInicialEnY
vz=vx; %VelocidadInicialEnZ
tiempo_final=d*40;

%Volcan
r = linspace(0,-17*pi) ;
th = linspace(0,-17*pi) ;
[R,T] = meshgrid(r,th) ;
Xd = R.*cos(T) ;
Yd = R.*sin(T) ;
Zd = R ;
surf(Xd,Yd,Zd)
hold on

%Calculo Oficial Con Friccion
VectoresX=[];
VectoresY=[];
VectoresZ=[];
contador=0;
for i= (0:40)
    fx=(-1*vx)*b; %FuerzaX
    fy=(-1*vy)*b; %FuerzaY
    fz=fx; %FuerzaZ
    ax=fx/m; %AceleraciónX
    ay=(-1*(fy/m))+g; %AceleraciónY
    az=ax; %AceleraciónZ
    %Posiciones
    if contador==0
        x=0*(x+vx*d);
        y=0*(y+vy*d);
        z=x;
        contador=contador+1;
    elseif contador==1
        x=x+(vx*d);
        y=y+(vy*d);
        z=x;
    end
    vx=vx+(d*ax);
    vy=vy+(d*ay);
    vz=vx;
    VectoresX=[VectoresX;x];
    VectoresY=[VectoresY;y];
    VectoresZ=VectoresX;
    ConFriccion=plot3(VectoresX,VectoresZ,VectoresY,'. green');
    verde=plot3(0,0,0,'. green');
    legend(verde,'Fricción Calculo')
    pause(0.1)
    title('Volcan en erupción con resistencia al aire')
    hold on
end

%Calculo Oficial Sin Friccion
xs=0; %PosicionInicialX
ys=0; %PosicionInicialY
zs=0; %PosicionInicialZ
vxs=vo*cos(a); %VelocidadInicialEnX
vys=vo*sin(a); %VelocidadInicialEnY
vzs=vxs; %VelocidadInicialEnZ
VectoresXs=[];
VectoresYs=[];
VectoresZs=[];
contadors=0;
for i= (0:40)
    tiempo=d*i;
    %Posiciones
    if contadors==0
        xs=0*(xs+vxs*tiempo);
        ys=0*(ys+vys*tiempo)+(0.5*g)*tiempo.^2;
        zs=xs;
        contadors=contadors+1;
    elseif contadors==1
        xs=(vxs*tiempo);
        ys=(vys*tiempo)+(0.5*g)*tiempo.^2;
        zs=xs;
    end
    VectoresXs=[VectoresXs;xs];
    VectoresYs=[VectoresYs;ys];
    VectoresZs=VectoresXs;
    SinFriccion=plot3(VectoresXs,VectoresZs,VectoresYs,'. red');
    rojo=plot3(0,0,0,'. red');
    legend(rojo,'Sin Fricción Calculo')
    pause(0.1)
    hold on
end

%Calculo 1
x1=0; %PosicionInicialX
y1=0; %PosicionInicialY
z1=0; %PosicionInicialZ
vo1=25; %Vo
a1=0.43; %Angulo
vx1=vo1*cos(a1); %VelocidadInicialEnX
vy1=vo1*sin(a1); %VelocidadInicialEnY
vz1=vx1; %VelocidadInicialEnZ
VectoresX1=[];
VectoresY1=[];
VectoresZ1=[];
contador1=0;
for i= (0:28)
    fx1=(-1*vx1)*b; %FuerzaX
    fy1=(-1*vy1)*b; %FuerzaY
    fz1=fx1; %FuerzaZ
    ax1=fx1/m; %AceleraciónX
    ay1=(-1*(fy1/m))+g; %AceleraciónY
    az1=ax1; %AceleraciónZ
    %Posiciones
    if contador1==0
        x1=0*(x1+vx1*d);
        y1=0*(y1+vy1*d);
        z1=x1;
        contador1=contador1+1;
    elseif contador1==1
        x1=x1+(vx1*d);
        y1=y1+(vy1*d);
        z1=x1;
        vx=vx+(d*ax);
    end
    vx1=vx1+(d*ax1);
    vy1=vy1+(d*ay1);
    vz1=vx1;
    VectoresX1=[VectoresX1;x1];
    VectoresY1=[VectoresY1;y1];
    VectoresZ1=VectoresX1;
    ProyectilPromedio1=plot3(VectoresX1,-VectoresZ1,VectoresY1,'. blue');
    blue=plot3(0,0,0,'. blue');
    legend(blue,'P1 Fricción')
    pause(0.1)
    hold on
end

%Calculo 1 Sin Fricción
xs1=0; %PosicionInicialX
ys1=0; %PosicionInicialY
zs1=0; %PosicionInicialZ
vxs1=25*cos(0.43); %VelocidadInicialEnX
vys1=25*sin(0.43); %VelocidadInicialEnY
vzs1=vxs1; %VelocidadInicialEnZ
VectoresXs1=[];
VectoresYs1=[];
VectoresZs1=[];
contadors1=0;
for i= (0:28)
    tiempos1=d*i;
    %Posiciones
    if contadors1==0
        xs1=0*(xs1+vxs1*tiempos1);
        ys1=0*(ys1+vys1*tiempos1)+(0.5*g)*tiempos1.^2;
        zs1=xs1;
        contadors1=contadors1+1;
    elseif contadors1==1
        xs1=(vxs1*tiempos1);
        ys1=(vys1*tiempos1)+(0.5*g)*tiempos1.^2;
        zs1=xs1;
    end
    VectoresXs1=[VectoresXs1;xs1];
    VectoresYs1=[VectoresYs1;ys1];
    VectoresZs1=VectoresXs1;
    SinFriccion1=plot3(VectoresXs1,-VectoresZs1,VectoresYs1,'. black');
    negro=plot3(0,0,0,'. black');
    legend(negro,'P1 Sin Fricción')
    pause(0.1)
    hold on
end

%Calculo 2
x2=0; %PosicionInicialX
y2=0; %PosicionInicialY
z2=0; %PosicionInicialZ
vo2=36; %Vo
a2=0.28; %Angulo
vx2=vo2*cos(a2); %VelocidadInicialEnX
vy2=vo2*sin(a2); %VelocidadInicialEnY
vz2=vx2; %VelocidadInicialEnZ
VectoresX2=[];
VectoresY2=[];
VectoresZ2=[];
contador2=0;
for i= (0:26)
    fx2=(-1*vx2)*b; %FuerzaX
    fy2=(-1*vy2)*b; %FuerzaY
    fz2=fx2; %FuerzaZ
    ax2=fx2/m; %AceleraciónX
    ay2=(-1*(fy2/m))+g; %AceleraciónY
    az2=ax2; %AceleraciónZ
    %Posiciones
    if contador2==0
        x2=0*(x2+vx2*d);
        y2=0*(y2+vy2*d);
        z2=x2;
        contador2=contador2+1;
    elseif contador2==1
        x2=x2+(vx2*d);
        y2=y2+(vy2*d);
        z2=x2;
        vx=vx+(d*ax);
    end
    vx2=vx2+(d*ax2);
    vy2=vy2+(d*ay2);
    vz2=vx2;
    VectoresX2=[VectoresX2;x2];
    VectoresY2=[VectoresY2;y2];
    VectoresZ2=VectoresX2;
    ProyectilPromedio2=plot3(-VectoresX2,VectoresZ2,VectoresY2,'. yellow');
    amarillo=plot3(0,0,0,'. yellow');
    legend(amarillo,'P2 Friccion')
    pause(0.1)
    hold on
end

%Calculo 2 Sin Fricción
xs2=0; %PosicionInicialX
ys2=0; %PosicionInicialY
zs2=0; %PosicionInicialZ
vxs2=36*cos(0.28); %VelocidadInicialEnX
vys2=36*sin(0.28); %VelocidadInicialEnY
vzs2=vxs2; %VelocidadInicialEnZ
VectoresXs2=[];
VectoresYs2=[];
VectoresZs2=[];
contadors2=0;
for i= (0:26)
    tiempos2=d*i;
    %Posiciones
    if contadors2==0
        xs2=0*(xs2+vxs2*tiempos2);
        ys2=0*(ys2+vys2*tiempos2)+(0.5*g)*tiempos2.^2;
        zs2=xs2;
        contadors2=contadors2+1;
    elseif contadors2==1
        xs2=(vxs2*tiempos2);
        ys2=(vys2*tiempos2)+(0.5*g)*tiempos2.^2;
        zs2=xs2;
    end
    VectoresXs2=[VectoresXs2;xs2];
    VectoresYs2=[VectoresYs2;ys2];
    VectoresZs2=VectoresXs2;
    SinFriccion2=plot3(-VectoresXs2,VectoresZs2,VectoresYs2,'. magenta');
    magenta=plot3(0,0,0,'. magenta');
    legend(magenta,'P2 Sin Fricción')
    pause(0.1)
    hold on
end

%Calculo 3
x3=0; %PosicionInicialX
y3=0; %PosicionInicialY
z3=0; %PosicionInicialZ
vo3=45; %Vo
a3=0.68; %Angulo
vx3=vo3*cos(a3); %VelocidadInicialEnX
vy3=vo3*sin(a3); %VelocidadInicialEnY
vz3=vx3; %VelocidadInicialEnZ
VectoresX3=[];
VectoresY3=[];
VectoresZ3=[];
contador3=0;
for i= (0:42)
    fx3=(-1*vx3)*b; %FuerzaX
    fy3=(-1*vy3)*b; %FuerzaY
    fz3=fx3; %FuerzaZ
    ax3=fx3/m; %AceleraciónX
    ay3=(-1*(fy3/m))+g; %AceleraciónY
    az3=ax3; %AceleraciónZ
    %Posiciones
    if contador3==0
        x3=0*(x3+vx3*d);
        y3=0*(y3+vy3*d);
        z3=x3;
        contador3=contador3+1;
    elseif contador3==1
        x3=x3+(vx3*d);
        y3=y3+(vy3*d);
        z3=x3;
        vx=vx+(d*ax);
    end
    vx3=vx3+(d*ax3);
    vy3=vy3+(d*ay3);
    vz3=vx3;
    VectoresX3=[VectoresX3;x3];
    VectoresY3=[VectoresY3;y3];
    VectoresZ3=VectoresX3;
    ProyectilPromedio3=plot3(-VectoresX3,-VectoresZ3,VectoresY3,'. cyan');
    cyan=plot3(0,0,0,'. cyan');
    legend(cyan,'P3 Friccion')
    pause(0.1)
    hold on
end

%Calculo 3 Sin Fricción
xs3=0; %PosicionInicialX
ys3=0; %PosicionInicialY
zs3=0; %PosicionInicialZ
vxs3=45*cos(0.68); %VelocidadInicialEnX
vys3=45*sin(0.68); %VelocidadInicialEnY
vzs3=vxs3; %VelocidadInicialEnZ
VectoresXs3=[];
VectoresYs3=[];
VectoresZs3=[];
contadors3=0;
for i= (0:42)
    tiempos3=d*i;
    %Posiciones
    if contadors3==0
        xs3=0*(xs3+vxs3*tiempos3);
        ys3=0*(ys3+vys3*tiempos3)+(0.5*g)*tiempos3.^2;
        zs3=xs3;
        contadors3=contadors3+1;
    elseif contadors3==1
        xs3=(vxs3*tiempos3);
        ys3=(vys3*tiempos3)+(0.5*g)*tiempos3.^2;
        zs3=xs3;
    end
    VectoresXs3=[VectoresXs3;xs3];
    VectoresYs3=[VectoresYs3;ys3];
    VectoresZs3=VectoresXs3;
    SinFriccion3=plot3(-VectoresXs3,-VectoresZs3,VectoresYs3,'. black');
    black=plot3(0,0,0,'. black');
    legend(black,'P3 Sin Fricción')
    pause(0.1)
    hold on
end
pause(2)
final=plot3(0,0,0,'* white');
legend(final, 'Final')
hold on
