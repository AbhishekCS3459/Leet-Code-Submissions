class Solution {
public:
  // this code will show tle error 
    // bool reachingPoints(int sx, int sy, int tx, int ty) {
    //   // Time complexity == 2^n
    //   if(sx>tx)return false;
    //   if(sy>ty)return false;
    //    if(sx==tx && sy==ty){
    //      return true;
    //    } 
    //   return reachingPoints(sx+sy,sy,tx,ty) ||  reachingPoints(sx,sx+sy,tx,ty);
    // }
  
  // now start from back side so to elimanate the unnecarry path
//   bool reachingPoints(int sx,int sy,int tx,int ty){
//  if(sx==tx && sy==ty)return true;
    
//   }
  // Method 2 
  
   bool reachingPoints_internal(int sx, int sy, int tx, int ty)
    {
        if (sx > tx || sy > ty)
        {
            return false;
        }
        else if (sx == tx && sy == ty)
        {
            return true;
        }
        
        while (tx > sx && ty > sy)
        {
            if (tx > ty)
            {
                // implies previous path to this tx, ty should have to be tx-ty, ty 
                // and this could continue till either tx < ty i.e difference would be tx % ty
                // so instead of doing that repeatedly just go the final point where 
                // tx would have started before started adding ty to it repeatedly 
                tx = tx % ty;
            }
            else
            {
                // implies previous path to this tx, ty should have to be (tx, ty-tx)
                // and this could continue till either tx > ty i.e difference would be tx % ty
                // so instead of doing that repeatedly just go the final point where 
                // ty would have started before started adding tx to it repeatedly
                ty = ty % tx;
            }
        }
        
        if ((tx == sx) && ((ty - sy) % sx == 0) )
        {
            return true;
        }
        else if ((ty == sy) && ((tx - sx) % sy == 0))
        {
            return true;
        }
        
        return false;
    }
    
    
    bool reachingPoints(int sx, int sy, int tx, int ty)
    {
        // Method-1 : recurssion - will not work for larger numbers as stack will use up all the memory
		// return reachingPoints_recursive(sx, sy, tx, ty);
        
		// Method-2 : Effecient non recursive solution
        return reachingPoints_internal(sx, sy, tx, ty);
    }
  
};