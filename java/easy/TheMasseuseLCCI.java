
//C语言用了空间复杂度O[n].优化为O[1]
public class anmoshi {

    public static int massage(int[] nums) {
        int a = 0, b = 0;
        for (int i=0; i<nums.length; i++){
            int c = Math.max(b, a+nums[i]);
            a = b;
            b = c;
        }
        return b;
    }


    public static void main(String[] args) {

        int [] nums = {2,7,9,3,1};
        System.out.println(massage(nums));
    }
}
