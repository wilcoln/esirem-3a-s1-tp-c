n = 30;
A = load('worst.csv');
data_size = A(1:n,1);
ylabels = ["temps moyen (en coups d'horloge)";"ecart type temps (en coups d'horloge)";"nombre de permutations";"nombre de comparaisons"];
cases = ["random"; "worst"; "best"];
sorts = ["basic"; "bubble"; "quick"; "merge"; "insertion"];
crit = ["moy";"ecert";"perm","comp"];
for i=3:6
    hf = figure(i-2);
    % basic = A(1:n,i);
    %selection = A(n+1:2*n,i);
    %bubble = A(2*n+1:3*n,i);
    % insertion = A(3*n+1:4*n,i);
    %merge = A(4*n+1:5*n,i);
     merge = A(5*n+1:6*n, i);
    plot(data_size, merge);
    xlim([0 1400])
    grid on;
    title('Merge sort');
    ylabel(ylabels(i-2,:));
    xlabel('taille du tableau');
endfor