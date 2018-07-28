#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

    struct Point {
                     int64_t x;
                     int64_t y;
                 };

       struct TaxiTrack {
                     int64_t x;
                     int64_t y;
                     uint32_t t;
                     uint32_t id;
                 };

 int IsPointInsidePolygon (Point p, int Number, int x, int y)
 {
  int64_t i1, i2, n, N, S, S1, S2, S3, flag;
  N = Number;
  for (n=0; n<N; n++)
  {
   flag = 0;
   i1 = n < N-1 ? n + 1 : 0;
   while (flag == 0)
   {
    i2 = i1 + 1;
    if (i2 >= N)
      i2 = 0;
    if (i2 == (n < N-1 ? n + 1 : 0))
      break;
    S = abs (p[i1].x * (p[i2].y - p[n ].y) +
             p[i2].x * (p[n ].y - p[i1].y) +
             p[n].x  * (p[i1].y - p[i2].y));
    S1 = abs (p[i1].x * (p[i2].y - y) +
              p[i2].x * (y       - p[i1].y) +
              x       * (p[i1].y - p[i2].y));
    S2 = abs (p[n ].x * (p[i2].y - y) +
              p[i2].x * (y       - p[n ].y) +
              x       * (p[n ].y - p[i2].y));
    S3 = abs (p[i1].x * (p[n ].y - y) +
              p[n ].x * (y       - p[i1].y) +
              x       * (p[i1].y - p[n ].y));
    if (S == S1 + S2 + S3)
    {
     flag = 1;
     break;
    }
    i1 = i1 + 1;
    if (i1 >= N)
      i1 = 0;
   }
   if (flag == 0)
     break;
  }
  return flag;
 }

int main()
{    
    int N;

    std::vector<Point> ps;
    ps.reserve(100);


    std::cin >> N;
    for (int i=0; i < N; i++){
        Point p;
        std::cin >> p.x >> p.y;
        ps.push_back(p);
    }

    sort(begin(ps), end(ps), []( const Point& lhs, const Point& rhs ){
        return (lhs.x * lhs.y - rhs.y * rhs.x) < 0;
    });

    int M;
    std::cin >> M;
    std::vector<TaxiTrack> tts;
    tts.reserve(M);

    for(int i =0; i < M; i++){
        int i_tracks;
        std::cin >> i_tracks;

        TaxiTrack tt, ttf;
        tt.id = i;
        ttf.t = -1;
        for(int j =0; j< i_tracks; j++){
            
            std::cin >>tt.t >> tt.x >> tt.y;
            if (IsPointInsidePolygon(ps, ps.size(), tt.x, tt.y) && ttf.t == -1){
                ttf = tt;
            } else {
                ttf.t = -1;
            }

        }

        if (ttf.t != -1){
            tts.push_back(tt);
        }
    }


    sort( begin(tts), end(tts), [ ]( const TaxiTrack& lhs, const TaxiTrack& rhs )
    {
        if (lhs.t == rhs.t)
            return (lhs.id < rhs.id);

        return lhs.t < rhs.t;
    });

    /*
    for (TaxiTrack& tt: tts){
        std::cout << tt.id << " " << tt.t << std::endl;
    }
    */



    int K;
    std::cin >> K;
    int lti = 0;
    for (int i =0; i < K; i++){
        int t;
        std::cin >> t;
        if (lti < tts.size() && tts[lti].t <= t){
            std::cout << tts[lti].id+1 << " ";
            lti++;
        } else {
            std::cout << "-1 ";
        }

    }

    return 0;
}