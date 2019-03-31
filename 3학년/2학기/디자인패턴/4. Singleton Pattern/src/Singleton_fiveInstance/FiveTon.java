package Singleton_fiveInstance;

import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

public class FiveTon {
	private static List<FiveTon> fivetonList = Collections.synchronizedList(new LinkedList<FiveTon>());
	private static int index = 0;
	
	private FiveTon() {}
	
	public static FiveTon getInstance() {
		if(fivetonList.size() < 5) {
			synchronized(fivetonList) {
				if(fivetonList.size() < 5) {
					FiveTon fiveTon = new FiveTon();
					fivetonList.add(fiveTon);
					return fiveTon;
				}
			}
		}
		
		synchronized(fivetonList) {
			FiveTon ft = fivetonList.get(index);
			index = (index+1) % fivetonList.size();
			return ft;
		}
	}
	
	public int getSize() { return fivetonList.size(); }
	
}
