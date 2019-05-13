function plot_them(y,data_size, basic, selection, bubble, insertion, quick, merge)
plot(data_size, basic,'-', data_size, selection,'-', data_size, bubble,'-',data_size, insertion,'-',data_size, quick,'-',data_size, merge,'-');
xlim([0 1400]);
legend('tri basic', 'tri selection', 'tri bulle', 'tri insertion', 'tri rapide', 'tri fusion');
xlabel('data size');
ylabel(y);
grid on;
title('Comparaison des performances');
endfunction