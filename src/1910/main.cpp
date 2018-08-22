#include <iostream>
#include <tuple>
#include <vector>
#include <stdexcept>

std::tuple<uint32_t, uint32_t> max_sum(const std::vector<uint32_t>& arr, int k)
{
    if (arr.size() < k){
        throw std::invalid_argument("k must be greater array size");
    }

    uint32_t max_sum = 0;
    uint32_t i_start = 2;
    for (int i = 0; i < k; i++)
    max_sum += arr[i];

    uint32_t window_sum = max_sum;
    for (int i = k; i < arr.size(); i++)
    {
        window_sum += arr[i] - arr[i-k];
        if (window_sum > max_sum ){
            max_sum = window_sum;
            i_start = i;
        }
    }

    return std::make_tuple(max_sum, i_start);
}


int main()
{
    uint32_t n;
    std::cin >> n;

    std::vector<uint32_t> in;
    in.reserve(1000);

    for(int i = 0; i < n; i++){
        uint32_t t;
        std::cin >> t;
        in.push_back(t);
    }

    auto result  = max_sum(in, 3);
    std::cout << std::get<0>(result) << " " << std::get<1>(result) << std::endl;
    
    return 0;
}

