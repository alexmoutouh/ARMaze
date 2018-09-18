﻿using System;
using System.Runtime.InteropServices;

namespace Wrapper {
    public class CameraWrapper {
        public struct embededFunctions {
            //const string dllpath = "VideoStream.dll";
            const string dllpath = @"C:\Users\alexm\Documents\testclone\Core\x64\Debug\VideoStream.dll";
            [DllImport(dllpath, EntryPoint = "createCamera")]static public extern IntPtr CreateCameraInput();
            [DllImport(dllpath, EntryPoint = "disposeCamera")]static public extern void DisposeCameraInput(IntPtr pCam);
            [DllImport(dllpath, EntryPoint = "openStream")]static public extern void OpenStream(IntPtr pCam);
            [DllImport(dllpath, EntryPoint = "displayStream")] static public extern void DisplayStream(IntPtr pCam);
            [DllImport(dllpath, EntryPoint = "getLiveFrame")]static public extern byte CallFunction(IntPtr pCam);
            [DllImport(dllpath, EntryPoint = "createTest")] static public extern IntPtr CreateTest();
        }

        static private CameraWrapper instance = null;

        private CameraWrapper() {}

        static public CameraWrapper GetInstance() {
            if(instance == null)
                instance = new CameraWrapper();
            return instance;
        }

        static void Main(string[] args) {
            Console.WriteLine("Testing VideoStream.dll...");
            IntPtr test = embededFunctions.CreateCameraInput();
            embededFunctions.OpenStream(test);
            embededFunctions.DisplayStream(test);
            Console.ReadKey();
        }
    }
}
