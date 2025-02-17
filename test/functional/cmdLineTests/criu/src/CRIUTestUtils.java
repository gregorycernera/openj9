/*******************************************************************************
 * Copyright (c) 2022, 2022 IBM Corp. and others
 *
 * This program and the accompanying materials are made available under
 * the terms of the Eclipse Public License 2.0 which accompanies this
 * distribution and is available at https://www.eclipse.org/legal/epl-2.0/
 * or the Apache License, Version 2.0 which accompanies this distribution and
 * is available at https://www.apache.org/licenses/LICENSE-2.0.
 *
 * This Source Code may also be made available under the following
 * Secondary Licenses when the conditions for such availability set
 * forth in the Eclipse Public License, v. 2.0 are satisfied: GNU
 * General Public License, version 2 with the GNU Classpath
 * Exception [1] and GNU General Public License, version 2 with the
 * OpenJDK Assembly Exception [2].
 *
 * [1] https://www.gnu.org/software/classpath/license.html
 * [2] http://openjdk.java.net/legal/assembly-exception.html
 *
 * SPDX-License-Identifier: EPL-2.0 OR Apache-2.0 OR GPL-2.0 WITH Classpath-exception-2.0 OR LicenseRef-GPL-2.0 WITH Assembly-exception
 *******************************************************************************/
import java.nio.file.Paths;
import java.nio.file.Path;
import java.nio.file.Files;
import java.nio.file.attribute.PosixFilePermissions;
import java.io.File;
import java.io.IOException;

import org.eclipse.openj9.criu.*;

public class CRIUTestUtils {
	public static void deleteCheckpointDirectory(Path path) {
		try {
			if (path.toFile().exists()) {
				Files.walk(path)
				.map(Path::toFile)
				.forEach(File::delete);

				Files.deleteIfExists(path);
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static void createCheckpointDirectory(Path path) {
		try {
			path.toFile().mkdir();
			Files.setPosixFilePermissions(path, PosixFilePermissions.fromString("rwxrwxrwx"));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static void checkPointJVM(Path path) {
		if (CRIUSupport.isCRIUSupportEnabled()) {
			deleteCheckpointDirectory(path);
			createCheckpointDirectory(path);
			try {
				new CRIUSupport(path)
				.setLeaveRunning(false)
				.setShellJob(true)
				.setFileLocks(true)
				.checkpointJVM();
			} catch (RestoreException e) {
				e.printStackTrace();
			}

			deleteCheckpointDirectory(path);
		} else {
			System.err.println("CRIU is not enabled");
		}
	}
}
