//  Statistics_Calculation
//  Avaliable on Github
//  Created by Paul-1437 on 10/26/22.

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
struct info{
    string name;
    double value;
    string tag;
};
vector<info> nums;
//申请可变数组
bool compare(info a, info b){
    if (a.value<b.value) {
        return 1;
    }
    else
        return 0;
}
double even_median(int start, int end, string l, string u, string m){
//偶数个数值，求中间值
    int q=end-start+1;
    double med=0;
    vector <info> ::iterator n=nums.begin();
    //申请迭代器，遍历到中间值
    for (int i=1; i<start; i++){
        n++;
    }
    int i=1;
    for (; i<=q/2; i++){
        if (i==q/2) {
        //当找到(其中一个)中间值时 when (one of) the middle value is found
            med+=n->value;
                n->tag=m;
            n++;
            continue;
        }
        if (n->tag!="Median"){
            n->tag=l;
        }
        n++;
    }
    for (; i<=q; i++){
        if (i==(q/2)+1) {
        //当找到（其中一个）中间值时 when (one of) the middle value is found
            med+=n->value;
            n->tag=m;
            n++;
            continue;
        }
        if (n->tag!="Median"){
            n->tag=u;
        }
        n++;
    }
    med/=2;
    return med;
}
double odd_median(int start, int end, string l, string u, string m){
//奇数个数值，求中间值
    int q=end-start+1;
    double med=0;
    vector <info> ::iterator n=nums.begin();
    //申请迭代器，遍历到中间值
    for (int i=1; i<start; i++){
        n++;
    }
    int i=1;
    for (; i<=(q/2)+1; i++){
        if (n->tag!="Median"){
            n->tag=l;
        }
        if (i==(q/2)+1) {
        //当找到中间值时 when the middle value is found
            med=n->value;
            n->tag=m;
            n++;
            continue;
        }
        n++;
    }
    for (; i<=q; i++){
        n->tag=u;
        n++;
    }
    return med;
}
int main(int argc, const char * argv[]) {
    int quantity=0;
    double total=0;
    map<double, int> mode_v;
    map<string, int> freqent_category;
    cout<<"input follows (name,value) pattern, ends up with character ^"<<endl;
    while (1) {
    //输入并打包进可变数组 input to vector
        info temp;
        double temp_v;
        string s;
        cin>>s;
        freqent_category[s]+=1;
        if (s=="^") {
            break;
        }
        else{
            temp.name=s;
        }
        cin>>temp_v;
        mode_v[temp_v]++;
        total+=temp_v;
        temp.value=temp_v;
        nums.push_back(temp);
        quantity++;
    }
    double mean=total/double(quantity);
    sort(nums.begin(), nums.end(), compare);
    double median,q1,q3;
    if (quantity%2==0) {
    //when the quantity of the data is even numbers
        median=even_median(1, quantity,"", "","Median");
        if (quantity%4==0){
        //when lower half and upper half are even numbers
            q1=even_median(1, quantity/2,"low25%","low_mid","Q1");
            q3=even_median((quantity/2)+1, quantity,"up_mid","up25%","Q3");
        }
        else{
        //when lower half and upper half are odd numbers
            q1=odd_median(1, quantity/2,"low25%","low_mid","Q1");
            q3=odd_median((quantity/2)+1, quantity,"up_mid","up25%","Q3");
        }
    }
    else{
    //when the quantity of the data is odd numbers
        median=odd_median(1, quantity, "", "","Median");
        if ((quantity-1)%4==0){
        //when lower half and upper half are even numbers
            q1=even_median(1, quantity/2,"low25%","low_mid","Q1");
            q3=even_median((quantity/2)+1, quantity,"up_mid","up25%","Q3");
        }
        else{
        //when lower half and upper half are odd numbers
            q1=odd_median(1, quantity/2,"low25%","low_mid","Q1");
            q3=odd_median((quantity/2)+1, quantity,"up_mid","up25%","Q3");
        }
    }
    double end=0;
    vector <info> ::iterator n=nums.begin();
    cout<<endl;
    while (n!=nums.end()) {
    //遍历并输出所有值 traversal and outpput all values
        cout<<n->name<<' '<<n->value<<' '<<n->tag<<endl;
        end=n->value;
        n++;
    }
    double mode=0;
    int mode_count=0;
    map<double, int> ::iterator m=mode_v.begin();
    while (m!=mode_v.end()) {
    //遍历找出众数 traversal to find mode
        if (m->second>mode_count) {
            mode_count=m->second;
            mode=m->first;
        }
        m++;
    }
    string high_freq="^";
    int freq_count=0,freq_amount=0;
    map<string, int> ::iterator s=freqent_category.begin();
    while (s!=freqent_category.end()) {
    //遍历找出最频繁种类 traversal to find the most frequent category
        if (s->second>freq_count) {
            freq_amount=1;
            freq_count=s->second;
            high_freq=s->first;
        }
        if (high_freq!=s->first&&s->second==freq_count) {
            freq_amount++;
            high_freq+=", ";
            high_freq+=s->first;
        }
        s++;
    }
    //output
    printf("\nOverall\nQuantity(n): %d\n", quantity);
    if (freq_amount<=3) {
        cout<<"Most frequent value: "<<high_freq<<" "<<freq_count<<"times"<<endl;
    }
    printf("Mean: %.2f\n", mean);
    printf("Mode: %.2f, %d times\n", mode,mode_count);
    printf("Min: %.2f\n", nums.begin()->value);
    printf("Q1: %.2f\n", q1);
    printf("Median: %.2f\n", median);
    printf("Q3: %.2f\n", q3);
    printf("IQR: %.2f\n", q3-q1);
    printf("Max: %.2f\n", end);
    printf("Total value: %.2f\n", total);
    return 0;
}
