package recursive_listing;
import java.io.File;

public class RecursiveListing {
	public static void displayDirectory(String dir, int depth) {
		File directory = new File(dir);
		File[] fileList = directory.listFiles();
		
		for(File file : fileList) {
			for(int i = 0; i < depth; i++) {
				System.out.print("\t");
			}
			
			if(file.isDirectory()) {
				System.out.println(file.getName());
				displayDirectory(file.getPath(), depth+1);
			}
			else if(file.isFile()){
				System.out.println(file.getName());
			}
		}
	}
	
	public static void main(String[] args) {
		if(args.length == 0) {
			System.out.println("명령 인수를 입력하세요!");
			System.out.println("시스템이 종료됩니다.");
			return;
		}
		
		File directory = new File(args[0]);
		if(!directory.exists()) {
			System.out.println("존재하지 않는 경로입니다.");
			return;
		}
		
		System.out.println(args[0] + "의 Directory List");
		displayDirectory(args[0], 0);
	}
}
