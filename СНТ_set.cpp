set<pair<int, int> > hullk;
set<pair<int, int> > hullx;
const int maxn = 1000000;
int hullk_num[maxn];
int hullb_num[maxn];
int hullx_num[maxn];
int num = 0;

bool comp(int a, int b, int c, int d){
    if(a/b != c/d)return a/b < c/d;
    a %= b; c %= d;
    if(a == 0)return false;
    if(c == 0)return true;
    return comp(d, c, b, a);
}

int okr(int a, int b){
    int delt = 0;
    if(a % b != 0)delt++;
    if((a>0 && b>0) || (a<0 && b<0))return a/b+delt;
    else return -(abs(a)/abs(b));
}

void add(int k, int b){
    hullk.insert({k, num});
    auto pred = hullk.lower_bound({k, num});
    pred--;
    if(hullk.size() == 1){
        hullx.insert({inf, num});
        hullx_num[num] = inf;
    }
    else {
        int sec = okr((hullb_num[pred->second] - b), k - pred->first);
        hullx.insert({sec, num});
        hullx_num[num] = sec;
    }
    auto next = hullk.lower_bound({k, num});
    next++;
    if(next != hullk.end()){
        int sec = okr((hullb_num[next->second] - b), k - next->first);
        hullx.erase({hullx_num[next->second], next->second});
        hullx_num[next->second] = sec;
        hullx.insert({hullx_num[next->second], next->second});
    }
}

void ins(int k, int b){
    hullb_num[num] = b;
    hullk_num[num] = k;
    if(hullk.size() <= 1){
        add(k, b);
        num++;
        return;
    }
    auto last = hullk.lower_bound({k, num});
    bool b2 = false;
    auto last2 = last;
    if(last != hullk.begin()){
        last--;
        last2 = last;
        while(last2 != hullk.begin()){
            last--;

            if(!comp((hullb_num[last->second] - b), k - last->first, (hullb_num[last->second] - hullb_num[last2->second]), last2->first - last->first)){
                hullx.erase({hullx_num[last2->second], last2->second});
                hullk.erase(last2);
                b2 = true;
            }
            else break;

            last2 = last;
        }
    }
    last = hullk.lower_bound({k, num});
    if(last != hullk.end()){
        last2 = last;
        last++;
        while(last != hullk.end()){

            if(comp((hullb_num[last->second] - b), k - last->first, (hullb_num[last->second] - hullb_num[last2->second]), last2->first - last->first)){
                hullx.erase({hullx_num[last2->second], last2->second});
                hullk.erase(last2);
                b2 = true;
            }
            else break;

            last2 = last;
            last++;
        }
    }
    last = hullk.lower_bound({k, num});
    last2 = hullk.upper_bound({k, num});
    if(b2 || last == hullk.begin() || last2 == hullk.end()){
        add(k, b);
    }
    num++;
}

int ask(int x){
    auto i = hullx.lower_bound({x, inf});
    return hullk_num[i->second] * x + hullb_num[i->second];
}