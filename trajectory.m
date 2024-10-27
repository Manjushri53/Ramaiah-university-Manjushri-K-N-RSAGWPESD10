v0=input('enter intial velocityof ball in m/s and press return\n');
angle=(5:5:85);
g=9.81;
hold on
for angle = 5:5:85
    tges=(2*v0.*sin(angle.*(pi/180)))/g;
    t=linspace(0,tges);
    vx=v0.*cos(angle.*(pi/180));
    vy=v0.*sin(angle.*(pi/180));
    sx=vx.*t;
    sy=vy.*t-0.5*g.*t.^2;
    plot(sx,sy);
end
hold off