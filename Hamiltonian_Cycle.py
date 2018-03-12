import sys
import matplotlib.pyplot as plt
from pylab import *
import graphviz as gv
from collections import defaultdict
mpl.rcParams['font.sans-serif'] = ['SimHei']
mpl.rcParams['axes.unicode_minus']=False

L = []


                
def DFS_Stack(graph, nV, v, dest, L):
    stack = [[v]]
    while stack:
        path = stack.pop()
        
        for w in range(nV):
            if graph[path[-1]][w] == 1:
                if w == dest:
                    #print('find one solution')
                    L.append(path + [w])
                else:
                    if w not in path:
                        stack.append(path + [w])
            


##4 cities
dic = {0: '成都市', 1: '上海市', 2: '武汉市', 3: '广州市'}

weight_graph = [[None, (1433.2999999999993, 53.18), (2000.6999999999998, 39.82), (1958.5, 49.92)],
                [(10300.599999999999, 56.03), None, (5092.2, 34.9), (4412.8333, 44.42)],
                [(6726.5, 39.25), (997.5, 33.75), None, (2991.6, 37.2)],
                [(7217.7, 49.65), (2816.5999999999995, 44.7), (3855.7, 37.32), None]]



graph = []
for i in weight_graph:
    LL = []
    for j in i:
        if j == None:
            LL.append(0)
        else:
            LL.append(1)

    graph.append(LL)
    

for i in range(len(graph[0])):
    DFS_Stack(graph, len(graph[0]), i, i, L)





###初始状态
g1 = gv.Digraph(format='png')
matrix = graph

length = len(matrix[0])
##print(length)
for i in range(length):
    g1.node(str(i))


for i in range(length):
    for j in range(length):
        if matrix[i][j] != 0:
            g1.edge(str(i), str(j))


g1.graph_attr['overlap'] = 'scale'
g1.graph_attr['rankdir'] = 'LR'
filename = g1.render(filename='img/g2', view=True)



dic_result = {}
dic_string_num = {}
for path in L:

    total_time = 0
    total_profit = 0
    key = ''
    for i in range(len(path)):
        
        if i == len(path) - 1:
            key += f'{dic[path[i]]}'
        else:
            key += f'{dic[path[i]]}->'


    for j in range(len(path) - 1):
        total_time += weight_graph[path[j]][path[j + 1]][1]
        total_profit += weight_graph[path[j]][path[j + 1]][0]

    dic_result[key] = total_profit / total_time
    dic_string_num[key] = path


key_list_sorted = sorted(dic_result, key = lambda x:dic_result[x], reverse = True)
uniq_dic = {}
for key in key_list_sorted:
    s_key = f'{dic_result[key]:.2f}'
    if s_key not in uniq_dic:
        uniq_dic[float(s_key)] = key



L = [0] * int((max(uniq_dic) // 10 + 1))

dic_for_box_plot_1 = defaultdict(list)
dic_for_box_plot_2 = defaultdict(list)

profit_hour = []
for key in key_list_sorted:
    L[int(dic_result[key] // 10)] += 1
    profit_hour.append(round(dic_result[key], 2))
    dic_for_box_plot_1[int(dic_result[key] // 10)].append(round(dic_result[key], 2))

for key in dic_for_box_plot_1:
    dic_for_box_plot_2[f'{key * 10}-{(key + 1) * 10}'] = dic_for_box_plot_1[key]
    
profit_hour.sort() 

##prepare for graph 3
list_3 = []

for i in uniq_dic:
    list_3.append(i)

max_ = max(list_3)
min_ = min(list_3)
middle = list_3[len(list_3) // 2]
first_path = dic_string_num[uniq_dic[max_]]
first_path_string = uniq_dic[max_]

second_path = dic_string_num[uniq_dic[min_]]
second_path_string = uniq_dic[min_]

thrid_path = dic_string_num[uniq_dic[middle]]
thrid_path_string = uniq_dic[middle]


def get_time_profit(path, weight_graph):
    time_list = []
    profit_list_add = [0] * (len(path) - 1)
    profit_list_no_add = [0] * (len(path) - 1)

    
    for i in range(len(path) - 1):

        time_list.append(weight_graph[path[i]][path[i + 1]][1])

    for i in range(0, len(path) - 1):
        
        profit_list_no_add[i] = weight_graph[path[i]][path[i + 1]][0]
        profit_list_add[i] = weight_graph[path[i]][path[i + 1]][0]


    for i in range(1, len(profit_list_add)):
        profit_list_add[i] += profit_list_add[i - 1]

    for i in range(1, len(time_list)):
        time_list[i] += time_list[i - 1]

    return_time_list = []
    return_time_list.append(0)
    return_time_list.extend(time_list)

    return_pro_add_list = []
    return_pro_add_list.append(0)
    return_pro_add_list.extend(profit_list_add)

    return_pro_no_add_list = []
    return_pro_no_add_list.append(0)
    return_pro_no_add_list.extend(profit_list_no_add)
    return return_time_list, return_pro_add_list, return_pro_no_add_list

        
        
def draw_graph_3(first_path, second_path, thrid_path,first_path_string, second_path_string, thrid_path_string):
    first_time, first_pro_add, first_pro_no_add = get_time_profit(first_path, weight_graph)
    second_time, second_pro_add, second_pro_no_add = get_time_profit(second_path, weight_graph)
    third_time, third_pro_add, third_pro_no_add = get_time_profit(thrid_path, weight_graph)

    plt.figure(figsize=(10, 6))
    plt.plot(first_time, first_pro_add, 'x-', label = first_path_string)
    plt.plot(second_time, second_pro_add,'x-', label = second_path_string)
    plt.plot(third_time, third_pro_add, 'x-', label = thrid_path_string)
    plt.legend(loc='upper left')
    plt.xlabel('Time')
    plt.ylabel('Profit')
    plt.show()


def draw_graph_4(first_path, second_path, thrid_path,first_path_string, second_path_string, thrid_path_string):
    first_time, first_pro_add, first_pro_no_add = get_time_profit(first_path, weight_graph)
    second_time, second_pro_add, second_pro_no_add = get_time_profit(second_path, weight_graph)
    third_time, third_pro_add, third_pro_no_add = get_time_profit(thrid_path, weight_graph)

    vis_first_time = []
    for i in range(len(first_time) - 1):
        vis_first_time.extend([first_time[i], first_time[i + 1]])

    vis_print_time = vis_first_time[::]
    vis_first_pro = first_pro_add[::]

    for i in range(1, len(vis_first_pro)):
        vis_first_pro[i] -= vis_first_pro[i - 1]

    
    
    for i in range(len(vis_first_time) // 2):
        vis_first_time[2 * i] = vis_first_pro[i + 1]
        vis_first_time[2 * i + 1] = vis_first_pro[i + 1]
    
    vis_second_time = []
    for i in range(len(second_time) - 1):
        vis_second_time.extend([second_time[i], second_time[i + 1]])

    vis_print2_time = vis_second_time[::]
    vis_second_pro = second_pro_add[::]

    for i in range(1, len(vis_second_pro)):
        vis_second_pro[i] -= vis_second_pro[i - 1]

    for i in range(len(vis_second_time) // 2):
        vis_second_time[2 * i] = vis_second_pro[i + 1]
        vis_second_time[2 * i + 1] = vis_second_pro[i + 1]

    vis_third_time = []
    for i in range(len(third_time) - 1):
        vis_third_time.extend([third_time[i], third_time[i + 1]])

    vis_print3_time = vis_third_time[::]
    vis_third_pro = third_pro_add[::]

    for i in range(1, len(vis_third_pro)):
        vis_third_pro[i] -= vis_third_pro[i - 1]

    
    
    for i in range(len(vis_third_time) // 2):
        vis_third_time[2 * i] = vis_third_pro[i + 1]
        vis_third_time[2 * i + 1] = vis_third_pro[i + 1]

    plt.plot(vis_print_time, vis_first_time, 'x-', label = first_path_string)
    plt.plot(vis_print2_time, vis_second_time,'x-', label = second_path_string)
    plt.plot(vis_print3_time, vis_third_time, 'x-', label = thrid_path_string)
    plt.legend(loc='upper right')
    plt.xlabel('Time')
    plt.ylabel('Profit')
    plt.show()
    
import numpy as np

##picture 1
labels_1 = [None] * len(L)
for i in range(len(L)):
    labels_1[i] = f'{i * 10}-{(i + 1) * 10}'

def autolabel(rects):
    for rect in rects:
        height = rect.get_height()
        plt.text(rect.get_x()+rect.get_width()/2., 1.0*height, '%d' % int(height))

def draw_graph_1(labels, L):
    fig = plt.figure()
    y_pos = [i for i in range(len(L))]
    
    rects = plt.bar(y_pos, L, align='center')
    autolabel(rects)
    plt.xticks(y_pos, labels)
    
    plt.xlabel('Price/hour')
    plt.ylabel('Number')
    plt.show()

def box_plot(dic_for_box_plot_2):
    fig = plt.figure()
    labels = []
    data = []
    for key in dic_for_box_plot_2:
        labels.append(key)
        data.append(dic_for_box_plot_2[key])
        
    labels = labels[::-1]
    data = data[::-1]

    plt.boxplot(data, labels = labels, sym = "o")
    plt.show()




def draw_graph_2(profit_hour):
    fig = plt.figure()
    y_pos = [i for i in range(len(profit_hour))]
    x_label = [''] * len(y_pos)
    rects = plt.bar(y_pos, profit_hour, align='center')
    plt.xticks(y_pos, x_label)
    plt.xlabel('Category')
    plt.ylabel('Price/Hour')
    plt.show()

box_plot(dic_for_box_plot_2)
draw_graph_3(first_path, second_path, thrid_path,first_path_string, second_path_string, thrid_path_string)
draw_graph_4(first_path, second_path, thrid_path, first_path_string, second_path_string, thrid_path_string)
##


for key in key_list_sorted:
    print(f'{key}: profit/hour is: {dic_result[key]:.2f}')






