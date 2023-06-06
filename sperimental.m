clc
clear all
close all
hold on
grid on
title('Overall Plots', 'FontSize', 25)
xlabel('Dimension(n)', 'FontSize', 22)
ylabel('Elapsed time (clocks)', 'FontSize', 22)
fid = fopen('../test.txt', 'rt');
C = textscan(fid, '%7c%d%c%d%d%d%d%d%d%d%d');
InputSize = C{2};
TimeIS = C{4};
TimeMS = C{5};
TimeHS = C{6};
TimeQS = C{7};
TimeRQS = C{8};
TimeM3QS = C{9};
TimeTRQS = C{10};
TimeOPTRQS = C{11};

plot(InputSize, TimeIS, 'LineWidth', 2, 'DisplayName', 'InsertionSort');
plot(InputSize, TimeMS, 'LineWidth',2, 'DisplayName', 'MergeSort');
plot(InputSize, TimeHS, 'LineWidth',2, 'DisplayName', 'HybridSort');
plot(InputSize, TimeQS, 'LineWidth',2, 'DisplayName', 'QuickSort');
plot(InputSize, TimeRQS, 'LineWidth',2, 'DisplayName', 'RandomizedQuickSort');
plot(InputSize, TimeM3QS, 'LineWidth',2, 'DisplayName', 'MedianOfThreeQuickSort');
plot(InputSize, TimeTRQS, 'LineWidth',2, 'DisplayName', 'QuickSortTailRecursive');
plot(InputSize, TimeOPTRQS, 'LineWidth',2, 'DisplayName', 'OptimizedTailRecursive', 'Color', [1 0 0]);

lgd = legend;
lgd.FontSize = 14;
lgd.Title.String = 'Legenda';
%set(gca,'color',[0.005 0.12 0.24])