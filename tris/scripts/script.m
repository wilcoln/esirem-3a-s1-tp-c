n = 30;
A = load('best.csv');
data_size = A(1:n,1);
ylabels = ["temps moyen (en coups d'horloge)";"ecart type temps (en coups d'horloge)";"nombre de permutations";"nombre de comparaisons"];
for i=3:6
    figure(i-2);
    basic = A(1:n,i);
    selection = A(n+1:2*n,i);
    bubble = A(2*n+1:3*n,i);
    insertion = A(3*n+1:4*n,i);
    quick = A(4*n+1:5*n,i);
    merge = A(5*n+1:6*n, i);
    plot_them(ylabels(i-2,:),data_size, basic, selection, bubble, insertion, quick, merge);
endfor