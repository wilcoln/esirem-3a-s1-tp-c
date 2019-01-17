A = load('performances_10.csv');
data_size = A(1:20,1);

figure(1);
basic = A(1:20,3);
selection = A(21:40,3);
bubble = A(41:60,3);
insertion = A(61:80,3);
quick = A(81:100,3);
merge = A(101:120, 3);

plot_all(data_size, basic, selection, bubble, insertion, quick, merge);


figure(2);
basic = A(1:20,4);
selection = A(21:40,4);
bubble = A(41:60,4);
insertion = A(61:80,4);
quick = A(81:100,4);
merge = A(101:120, 4);

plot_all(data_size, basic, selection, bubble, insertion, quick, merge);


figure(3);
basic = A(1:20,5);
selection = A(21:40,5);
bubble = A(41:60,5);
insertion = A(61:80,5);
quick = A(81:100,5);
merge = A(101:120, 5);

plot_all(data_size, basic, selection, bubble, insertion, quick, merge);

figure(3);
data_size = A(1:20,1);
basic = A(1:20,6);
selection = A(21:40,6);
bubble = A(41:60,6);
insertion = A(61:80,6);
quick = A(81:100,6);
merge = A(101:120, 6);

plot_all(data_size, basic, selection, bubble, insertion, quick, merge);
