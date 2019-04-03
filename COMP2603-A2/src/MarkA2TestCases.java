
import com.ta.core.MarkingProcess;
import com.ta.core.ManualMarker;
import com.ta.core.TestCaseMarker;
import com.ta.core.BatchProcess.ItemAction;
import com.ta.core.CompilationResults;
import com.ta.sample.InsertHeader;
import com.ta.sample.TestCaseMaker;

import junit.framework.TestResult;
import junit.framework.TestSuite;

import java.io.File;

import org.junit.internal.TextListener;
import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;


public class MarkA2TestCases extends TestCaseMarker
{
	
	private String[] studentClassNames;
	private String[] testClassNames;
	
	public MarkA2TestCases(String sourceDir) {
		super(sourceDir);
		studentClassNames = new String[] {
				"Device"
				,"PortableDevice"
				,"AC"
				,"Fan"
				,"StandingFan"
				,"CeilingFan"
				,"Room"
				,"CoolingSimulation"
		};
		
		testClassNames = new String[] {
				"ACTest",
				"StandingFanTest",
				"CeilingFanTest",
				"CoolingSimulationTest",
				"RoomTest"
			};
	}
	
	@Override
	protected String[] getStudentClassNames() {
		return studentClassNames;
	}

	@Override
	protected String[] getTestCaseClassNames() {
		return testClassNames;
	}
	
	@Override
	protected void markStudentCompilation(CompilationResults cr){
		
		for(String className : cr.getFailureCompilationArray()){
			System.out.println(className + " does not complie");
		}

		for(String className : cr.getSuccessCompilationArray()){
			System.out.println(className + " complies");
		}

//		for(String className : studentClassNames){
//			if(isClassLoaded(className)){
//				System.out.println(className + " compiles");
//			}
//			else{
//				System.out.println(className +" does not compile");
//			}
//		}
	}

}
