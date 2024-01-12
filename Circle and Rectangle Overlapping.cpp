class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
           int x = max(x1, min(xCenter, x2));     // nearest x coordinate to circle
      
        int y = max(y1, min(yCenter, y2));        // nearest y coordinate to circle
 
        int d1 = (x-xCenter) * (x-xCenter);        

        int d2 = (y-yCenter) * (y-yCenter);

        return (d1+d2) <= (radius*radius);       
    }
};
