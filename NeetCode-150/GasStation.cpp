//using greedy
//first we can prove that if total(gas) >= total(cost) then there must exist atleast one solution(here only one unique solution as its said in the q)
//else we return -1
//now we start from 0, have a sum which keep tracks of how much gas we have left and res which is the starting index
//if sum ever becomes negative we can be SURE that whatever the starting index was isnt gonna work since we wont be able to cross a station
//now when at ith station we get negative gas remaining, we start from next index as starting index
//reason we dont start somewhere back but after the original starting index is because say original starting index was 0 and we got negative gas at 5, if we start from 3 we know at 3 THERE was some positive gas left (since we would stop if gas ever became negative) but despite having some gas left from 3 to 5 the remaining gas became negative so if we do start from 3 we can be sure that gas would become even more negative by the time we reach 5 or even before(like 4)
//so we set i+1 as the new starting index , now from 5 to till the end if we always have remaining gas >= 0 we can be sure starting index wouldnt be between 5 and end say 10 as by the time we reach 10 we would deffo have some gas left so why start at 10 with lesser starting gas when we can start earlier and have more gas left by the time we reach 10 as compared to starting directly from 10
//also theres a proof that if in a circular table theres n integers and sum of them is >= 0 then there will EXIST a number starting with which we can go around the table with the cummulative sum always being >= 0.
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) {
            return -1;
        }
        int res = 0;
        int sum = 0;
        for(int i = 0;i < gas.size() ; i++){
            sum += gas[i] - cost[i];
            if(sum < 0){
                res = i + 1;
                sum = 0;
            }
        }
        return res;
    }
};