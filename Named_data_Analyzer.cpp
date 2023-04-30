//  Statistics_Calculation
//  Avaliable on Github
//  Created by Paul-1437 on 10/26/22.

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
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
    cout<<"input follows (name,value) pattern, ends up with character ^"<<endl;
    while (1) { //输入并打包进vector可变数组
        info temp;
        double temp_v;
        string s;
        cin>>s;
        if (s=="^") {
            break;
        }
        else{
            temp.name=s;
        }
        cin>>temp_v;
        total+=temp_v;
        temp.value=temp_v;
        nums.push_back(temp);
        quantity++;
    }
    double mean=total/double(quantity);
    sort(nums.begin(), nums.end(), compare);
    double median,q1,q3;
    //when the quantity of the data is even
    if (quantity%2==0) {
        median=even_median(1, quantity,"", "","Median");
        //when lower half and upper half are even
        if (quantity%4==0){
            q1=even_median(1, quantity/2,"low25%","low_mid","Q1");
            q3=even_median((quantity/2)+1, quantity,"up_mid","up25%","Q3");
        }
        //when lower half and upper half are odd
        else{
            q1=odd_median(1, quantity/2,"low25%","low_mid","Q1");
            q3=odd_median((quantity/2)+1, quantity,"up_mid","up25%","Q3");
        }
    }
    //when the quantity of the data is odd
    else{
        median=odd_median(1, quantity, "", "","Median");
        //when lower half and upper half are even
        if ((quantity-1)%4==0){
            q1=even_median(1, quantity/2,"low25%","low_mid","Q1");
            q3=even_median((quantity/2)+1, quantity,"up_mid","up25%","Q3");
        }
        //when lower half and upper half are odd
        else{
            q1=odd_median(1, quantity/2,"low25%","low_mid","Q1");
            q3=odd_median((quantity/2)+1, quantity,"up_mid","up25%","Q3");
        }
    }
    double end=0;
    vector <info> ::iterator n=nums.begin();
    while (n!=nums.end()) {
        cout<<n->name<<' '<<n->value<<' '<<n->tag<<endl;
        end=n->value;
        n++;
    }
    printf("\nOverall\nQuantity(n): %d\n", quantity);
    printf("Mean: %.2f\n", mean);
    printf("Min: %.2f\n", nums.begin()->value);
    printf("Q1: %.2f\n", q1);
    printf("Median: %.2f\n", median);
    printf("Q3: %.2f\n", q3);
    printf("Max: %.2f\n", end);
    printf("Total: %.2f\n", total);
    return 0;
}
