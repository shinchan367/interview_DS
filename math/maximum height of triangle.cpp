class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        return max(fun(red,blue),fun(blue,red));
    }

    int fun(int a,int b){
        int h=0;
        int i=1;
        while(true){
            if(i%2==1){
                if(a>=i){
                    a-=i;
                }
                else{
                    break;
                }
            }
            else{
                if(b>=i){
                    b-=i;
            }
            else{
                break;
            }
            }
            h++;
            i++;

        }
        return h;
    }
};
