xmin = 0.4;
xmax = 0.6;
N = 100;
X = xmin+(xmax-xmin)*rand(1,N);
Y = zeros(1,N);
figure
subplot(2,1,1)
plot(X,Y,'*')
xlim([0 1])
subplot(2,1,2)
hist(X)
xlim([0 1])
hold off;