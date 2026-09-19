// class Solution {
// public:
//     bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1,
//                       int x2, int y2) {
//         int ans = false;
//         if (xCenter > x1 && xCenter < x2 && yCenter > y1 && yCenter < y2) {

//             ans = true;
//             return ans;
//         }
//         for (int x = xCenter - radius; x <= xCenter + radius; x++) {
//             for (int y = yCenter - radius; y <= yCenter + radius; y++) {
//                 int r = radius;
//                 if ((x - xCenter) * (x - xCenter) +
//                         (y - yCenter) * (y - yCenter) ==
//                     r * r) {

//                     if (x > x1 && x < x2 && y > y1 && y < y2) {

//                         ans = true;
//                         return ans;
//                     }
//                 }
//             }
//         }

//         for (int i = x1; i < x2; i++) {
//             int x = abs(i - xCenter);
//             int y = abs(y1 - yCenter);
//             int yy = abs(y2 - yCenter);
//             double dist = sqrt(((x * x) + (y * y)));
//             double dist2 = sqrt(((x * x) + (yy * yy)));

//             if (dist <= radius || dist2 <= radius) {
//                 ans = true;
//                 break;
//             }
//         }
//         for (int i = y1; i < y2; i++) {
//             int x = abs(i - xCenter);
//             int y = abs(x1 - yCenter);
//             int yy = abs(x2 - yCenter);
//             double dist = sqrt(((x * x) + (y * y)));
//             double dist2 = sqrt(((x * x) + (yy * yy)));

//             if (dist <= radius || dist2 <= radius) {
//                 ans = true;
//                 break;
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    bool checkOverlap(int radius, int xC, int yC, int x1, int y1, int x2, int y2) {
        int x , y ; 
            if( xC < x1 ) x = x1; 
           else if( xC > x2) x = x2;
           else x = xC;

           if( yC < y1 ) y = y1; 
           else if( yC > y2) y = y2;
           else y = yC;


           
           int dx = abs(x - xC);
           int dy = abs(y - yC);
           if( radius * radius >= (dx*dx)+(dy*dy)) return true; 
           else return false; 
        }
};