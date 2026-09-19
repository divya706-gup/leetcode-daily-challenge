class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int a=max(x1,min(x2,xCenter));
        int b=max(y1,min(y2,yCenter));
        int distance =((xCenter-a)*(xCenter-a))+((yCenter-b)*(yCenter-b));
        return distance<=radius*radius;
    }
};