A = load('perf.csv');

data_size = A(1:20,1);
basic = A(1:20,3);
selection = A(21:40,3);
bubble = A(41:60,3);
insertion = A(61:80,3);
quick = A(81:100,3);

subplot(2,3,1);
plot(data_size, basic);
ylabel('tri basic');
subplot(2,3,2);
plot(data_size, selection);
subplot(2,3,3);
plot(data_size, bubble);
subplot(2,3,4);
plot(data_size, insertion);
subplot(2,3,5);
plot(data_size, quick);