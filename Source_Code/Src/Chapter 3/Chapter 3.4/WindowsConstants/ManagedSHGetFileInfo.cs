using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;
using System.IO;
using System.Drawing;

namespace WindowsConstants
{
    
    //Win32 definition
    //typedef struct _SHFILEINFO {
    //    HICON hIcon;
    //    int iIcon;
    //    DWORD dwAttributes;
    //    TCHAR szDisplayName[MAX_PATH];
    //    TCHAR szTypeName[80];
    //} SHFILEINFO;

    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Auto)]
    public struct SHFILEINFO
    {
        public IntPtr hIcon;
        public IntPtr iIcon;
        public uint dwAttributes;
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 260)]
        public string szDisplayName;
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 80)]
        public string szTypeName;
    }

    [Flags]
    public enum FileInfoFlags : int
    {
        SHGFI_LARGEICON = 0x000000, // 获得大图标
        SHGFI_SMALLICON = 0x000001, // 获得小图标
        SHGFI_OPENICON = 0x000002, // 获得打开图标
        SHGFI_SHELLICONSIZE = 0x000004, // 获得外壳图标
        SHGFI_PIDL = 0x000008, // pszPath是pidl
        SHGFI_USEFILEATTRIBUTES = 0x000010, // 使用传递的dwFileAttribute
        SHGFI_ICON = 0x000100,  // 获得图标
        SHGFI_ADDOVERLAYS = 0x000000020,  // 使用恰当的重叠
        SHGFI_OVERLAYINDEX = 0x000000040,  // 获得图标最上面8位中重叠的索引
        SHGFI_DISPLAYNAME = 0x000200,  //获得显示的名称
        SHGFI_TYPENAME = 0x000400,  // 获得类型的名称
        SHGFI_ATTRIBUTES = 0x000800,  // 获得属性
        SHGFI_ICONLOCATION = 0x001000,  // 获得图标的位置
        SHGFI_EXETYPE = 0x002000,  // 返回exe的类型
        SHGFI_SYSICONINDEX = 0x004000,  // 获得系统图标索引
        SHGFI_LINKOVERLAY = 0x008000,  // 在图标上放置一个小箭头标识
        SHGFI_SELECTED = 0x010000,  // 显示处于选中状态下的图标
        SHGFI_ATTR_SPECIFIED = 0x020000,  // 只获得指定的属性
        s
    }

    [Flags]
    public enum FileAttributeFlags : uint
    {
        //文件属性标志
        FILE_ATTRIBUTE_READONLY = 0x00000001,
        FILE_ATTRIBUTE_HIDDEN = 0x00000002,
        FILE_ATTRIBUTE_SYSTEM = 0x00000004,
        FILE_ATTRIBUTE_DIRECTORY = 0x00000010,
        FILE_ATTRIBUTE_ARCHIVE = 0x00000020,
        FILE_ATTRIBUTE_DEVICE = 0x00000040,
        FILE_ATTRIBUTE_NORMAL = 0x00000080,
        FILE_ATTRIBUTE_TEMPORARY = 0x00000100,
        FILE_ATTRIBUTE_SPARSE_FILE = 0x00000200,
        FILE_ATTRIBUTE_REPARSE_POINT = 0x00000400,
        FILE_ATTRIBUTE_COMPRESSED = 0x00000800,
        FILE_ATTRIBUTE_OFFLINE = 0x00001000,
        FILE_ATTRIBUTE_NOT_CONTENT_INDEXED = 0x00002000,
        FILE_ATTRIBUTE_ENCRYPTED = 0x00004000,
        FILE_ATTRIBUTE_VALID_FLAGS = 0x00007fb7,
        FILE_ATTRIBUTE_VALID_SET_FLAGS = 0x000031a7,
    }

    class ManagedSHGetFileInfo
    {
        //Win32 API
        //DWORD_PTR SHGetFileInfo(
        //    LPCTSTR pszPath,
        //    DWORD dwFileAttributes,
        //    SHFILEINFO* psfi,
        //    UINT cbFileInfo,
        //    UINT uFlags
        //);

        [DllImport("shell32.dll", CharSet = CharSet.Auto)]
        public static extern IntPtr SHGetFileInfo(
            string pszPath,
            uint dwFileAttributes,
            ref SHFILEINFO psfi,
            uint cbFileInfo,
            uint uFlags);
    }

    [Flags]
    public enum CSIDLFlags : int // 本代码页最后列出了有关这些flag的全部信息
    {
        CSIDL_DESKTOP = 0,
        CSIDL_INTERNET,
        CSIDL_PROGRAMS,
        CSIDL_CONTROLS,
        CSIDL_PRINTERS,
        CSIDL_PERSONAL,
        CSIDL_FAVORITES,
        CSIDL_STARTUP,
        CSIDL_RECENT,
        CSIDL_SENDTO,
        CSIDL_BITBUCKET,
        CSIDL_STARTMENU, // = 11
        CSIDL_DESKTOPDIRECTORY = 16,
        CSIDL_DRIVES,
        CSIDL_NETWORK,
        CSIDL_NETHOOD,
        CSIDL_FONTS,
        CSIDL_TEMPLATES,
        CSIDL_COMMON_STARTMENU,
        CSIDL_COMMON_PROGRAMS,
        CSIDL_COMMON_STARTUP,
        CSIDL_COMMON_DESKTOPDIRECTORY,
        CSIDL_APPDATA,
        CSIDL_PRINTHOOD,
        CSIDL_LOCAL_APPDATA,
        CSIDL_ALTSTARTUP,
        CSIDL_COMMON_ALTSTARTUP,
        CSIDL_COMMON_FAVORITES,
        CSIDL_INTERNET_CACHE,
        CSIDL_COOKIES,
        CSIDL_HISTORY,
        CSIDL_COMMON_APPDATA,
        CSIDL_WINDOWS,
        CSIDL_SYSTEM,
        CSIDL_PROGRAM_FILES,
        CSIDL_MYPICTURES,
        CSIDL_PROFILE,
        CSIDL_SYSTEMX86,
        CSIDL_PROGRAM_FILESX86,
        CSIDL_PROGRAM_FILES_COMMON,
        CSIDL_PROGRAM_FILES_COMMONX86,
        CSIDL_COMMON_TEMPLATES,
        CSIDL_COMMON_DOCUMENTS,
        CSIDL_COMMON_ADMINTOOLS,
        CSIDL_ADMINTOOLS,
        CSIDL_CONNECTIONS, // =49
        CSIDL_COMMON_MUSIC = 53,
        CSIDL_COMMON_PICTURES,
        CSIDL_COMMON_VIDEO,
        CSIDL_RESOURCES,
        CSIDL_RESOURCES_LOCALIZED,
        CSIDL_COMMON_OEM_LINKS,
        CSIDL_CDBURN_AREA, // = 59
        CSIDL_COMPUTERSNEARME = 61,
        CSIDL_FLAG_DONT_VERIFY = 0x4000,
        CSIDL_FLAG_CREATE = 0x8000,
        CSIDL_FLAG_MASK = 0xFF00,
    }

    public enum IconSize
    {
        Large = 0, //32 X 32 pixels.
        Small = 1 //16 X 16 pixels.
    }

    class ManagedSHGetFileInfoWrapper
    {
        /// <summary>
        /// 此方法用于获得一个文件类型的名称
        /// </summary>
        /// <param name="path">文件的路径</param>
        /// <returns></returns>
        public static string GetFileTypeName(string filePath)
        {
            if (!File.Exists(filePath))
            {
                throw new FileNotFoundException(filePath);
            }

            try
            {
                SHFILEINFO fileInfo = new SHFILEINFO();
                int cbFileInfo = Marshal.SizeOf(fileInfo);
                uint dwflag = (uint)(FileInfoFlags.SHGFI_TYPENAME | FileInfoFlags.SHGFI_USEFILEATTRIBUTES);

                uint dwAttr = (uint)FileAttributeFlags.FILE_ATTRIBUTE_NORMAL;
                IntPtr hr = ManagedSHGetFileInfo.SHGetFileInfo(filePath, dwAttr, ref fileInfo, 
                    (uint)Marshal.SizeOf(fileInfo), dwflag);
                return fileInfo.szTypeName;
            }
            catch (Exception e)
            {
                throw e;
            }
        }

        /// <summary>
        /// 获得文件的图标
        /// </summary>
        /// <param name="filePath">文件的路径</param>
        /// <param name="linkOverlay">是否显示图标上的快捷方式小箭头</param>
        /// <param name="iconSize">要显示的图标大小</param>
        /// <returns></returns>
        public static Icon GetFileIcon(string filePath, bool linkOverlay, IconSize iconSize)
        {
            if (!File.Exists(filePath))
            {
                throw new FileNotFoundException(filePath);
            }

            SHFILEINFO fileInfo = new SHFILEINFO();
            uint dwflags = (uint)(FileInfoFlags.SHGFI_ICON | FileInfoFlags.SHGFI_USEFILEATTRIBUTES);

            if (linkOverlay)
            {
                dwflags += (uint)FileInfoFlags.SHGFI_LINKOVERLAY;
            }

            if (iconSize == IconSize.Small)
            {
                dwflags += (uint)FileInfoFlags.SHGFI_SMALLICON;
            }
            else if (iconSize == IconSize.Large)
            { 
                dwflags += (uint)FileInfoFlags.SHGFI_LARGEICON;
            }

            ManagedSHGetFileInfo.SHGetFileInfo(filePath,
                (uint)FileAttributeFlags.FILE_ATTRIBUTE_NORMAL,
                ref fileInfo,
                (uint)Marshal.SizeOf(fileInfo),
                dwflags);

            // 将Win32 API函数返回的图标拷贝到托管Icon对象中
            Icon icon = (Icon)Icon.FromHandle(fileInfo.hIcon).Clone();

            // 使用Win32 API函数释放掉这个图标
            DestroyIcon(fileInfo.hIcon);

            return icon;
        }

        //Win32 API
        //BOOL DestroyIcon(
        //    HICON hIcon
        //);

        // 销毁图标并释放掉由此图标所占据的内存
        [DllImport("User32.dll")]
        private static extern int DestroyIcon(IntPtr hIcon);
    }

    class ManagedSHGetFileInfoTest
    {

        //Win32 API
        //HRESULT SHGetFolderLocation(
        //    HWND hwndOwner,
        //    int nFolder,
        //    HANDLE hToken,
        //    DWORD dwReserved,
        //    PIDLIST_ABSOLUTE* ppidl
        //);

        [DllImport("shell32.dll")]
        static extern int SHGetFolderLocation(
            IntPtr hwndOwner, 
            int nFolder,
            IntPtr hToken,
            uint dwReserved,
            out IntPtr ppidl  // 调用方需要通过调用ILFree来负责释放此资源
            );

        //Win32 API
        //void ILFree(
        //    PIDLIST_RELATIVE pidl
        //);

        [DllImport("shell32.dll")]
        public static extern void ILFree(
            IntPtr pidl); 

        public const int S_OK = 0x00000000;

        /// <summary>
        /// 获得一个应用程序显示的名称，比如“我的电脑”，“回收站”等等
        /// </summary>
        public static void FetchProcDisplayName()
        {
            IntPtr pidl1 = IntPtr.Zero;
            int result = SHGetFolderLocation(IntPtr.Zero, 
                (int)CSIDLFlags.CSIDL_BITBUCKET,
                IntPtr.Zero, 
                0, 
                out pidl1);

            if (result == S_OK)
            {
                SHFILEINFO fileInfo = new SHFILEINFO();

                string filePath = Marshal.PtrToStringAuto(pidl1); //获得了指定CSIDL的路径
                ManagedSHGetFileInfo.SHGetFileInfo(filePath, 
                    0, 
                    ref fileInfo,
                    (uint)Marshal.SizeOf(fileInfo),
                    (uint)(FileInfoFlags.SHGFI_PIDL | 
                    FileInfoFlags.SHGFI_DISPLAYNAME));

                Console.WriteLine(fileInfo.szDisplayName);
            }

            // 释放pidl1
            ILFree(pidl1);
        }
    }



}

/*
CSIDL

Note  In Windows Vista, these values have been replaced by KNOWNFOLDERID values. See that topic for a list of the new constants and their corresponding CSIDL values. For convenience, corresponding KNOWNFOLDERID values are also noted here for each CSIDL value.

The CSIDL system is supported under Windows Vista for compatibility reasons. However, new development should use KNOWNFOLDERID values rather than CSIDL values.

CSIDL (constant special item ID list) values provide a unique system-independent way to identify special folders used frequently by applications, but which may not have the same name or location on any given system. For example, the system folder may be "C:\Windows" on one system and "C:\Winnt" on another. These constants are defined in Shlobj.h. A subset of them is also defined in Shfolder.h.

Constants

    CSIDL_ADMINTOOLS (FOLDERID_AdminTools)
        Version 5.0. The file system directory that is used to store administrative tools for an individual user. The Microsoft Management Console (MMC) will save customized consoles to this directory, and it will roam with the user.

    CSIDL_ALTSTARTUP (FOLDERID_Startup)
        The file system directory that corresponds to the user's nonlocalized Startup program group. This value is recognized in Windows Vista for backward compatibility, but the folder itself no longer exists.

    CSIDL_APPDATA (FOLDERID_RoamingAppData)
        Version 4.71. The file system directory that serves as a common repository for application-specific data. A typical path is C:\Documents and Settings\username\Application Data. This CSIDL is supported by the redistributable Shfolder.dll for systems that do not have the Microsoft Internet Explorer 4.0 integrated Shell installed.

    CSIDL_BITBUCKET (FOLDERID_RecycleBinFolder)
        The virtual folder that contains the objects in the user's Recycle Bin.

    CSIDL_CDBURN_AREA (FOLDERID_CDBurning)
        Version 6.0. The file system directory that acts as a staging area for files waiting to be written to a CD. A typical path is C:\Documents and Settings\username\Local Settings\Application Data\Microsoft\CD Burning.

    CSIDL_COMMON_ADMINTOOLS (FOLDERID_CommonAdminTools)
        Version 5.0. The file system directory that contains administrative tools for all users of the computer.

    CSIDL_COMMON_ALTSTARTUP (FOLDERID_CommonStartup)
        The file system directory that corresponds to the nonlocalized Startup program group for all users. Valid only for Microsoft Windows NT systems. This value is recognized in Windows Vista for backward compatibility, but the folder itself no longer exists.

    CSIDL_COMMON_APPDATA (FOLDERID_ProgramData)
        Version 5.0. The file system directory that contains application data for all users. A typical path is C:\Documents and Settings\All Users\Application Data. This folder is used for application data that is not user specific. For example, an application can store a spell-check dictionary, a database of clip art, or a log file in the CSIDL_COMMON_APPDATA folder. This information will not roam and is available to anyone using the computer.

    CSIDL_COMMON_DESKTOPDIRECTORY (FOLDERID_PublicDesktop)
        The file system directory that contains files and folders that appear on the desktop for all users. A typical path is C:\Documents and Settings\All Users\Desktop. Valid only for Windows NT systems.

    CSIDL_COMMON_DOCUMENTS (FOLDERID_PublicDocuments)
        The file system directory that contains documents that are common to all users. A typical paths is C:\Documents and Settings\All Users\Documents. Valid for Windows NT systems and Microsoft Windows 95 and Windows 98 systems with Shfolder.dll installed.

    CSIDL_COMMON_FAVORITES (FOLDERID_Favorites)
        The file system directory that serves as a common repository for favorite items common to all users. Valid only for Windows NT systems.

    CSIDL_COMMON_MUSIC (FOLDERID_PublicMusic)
        Version 6.0. The file system directory that serves as a repository for music files common to all users. A typical path is C:\Documents and Settings\All Users\Documents\My Music.

    CSIDL_COMMON_OEM_LINKS (FOLDERID_CommonOEMLinks)
        This value is recognized in Windows Vista for backward compatibility, but the folder itself is no longer used.

    CSIDL_COMMON_PICTURES (FOLDERID_PublicPictures)
        Version 6.0. The file system directory that serves as a repository for image files common to all users. A typical path is C:\Documents and Settings\All Users\Documents\My Pictures.

    CSIDL_COMMON_PROGRAMS (FOLDERID_CommonPrograms)
        The file system directory that contains the directories for the common program groups that appear on the Start menu for all users. A typical path is C:\Documents and Settings\All Users\Start Menu\Programs. Valid only for Windows NT systems.

    CSIDL_COMMON_STARTMENU (FOLDERID_CommonStartMenu)
        The file system directory that contains the programs and folders that appear on the Start menu for all users. A typical path is C:\Documents and Settings\All Users\Start Menu. Valid only for Windows NT systems.

    CSIDL_COMMON_STARTUP (FOLDERID_CommonStartup)
        The file system directory that contains the programs that appear in the Startup folder for all users. A typical path is C:\Documents and Settings\All Users\Start Menu\Programs\Startup. Valid only for Windows NT systems.

    CSIDL_COMMON_TEMPLATES (FOLDERID_CommonTemplates)
        The file system directory that contains the templates that are available to all users. A typical path is C:\Documents and Settings\All Users\Templates. Valid only for Windows NT systems.

    CSIDL_COMMON_VIDEO (FOLDERID_PublicVideos)
        Version 6.0. The file system directory that serves as a repository for video files common to all users. A typical path is C:\Documents and Settings\All Users\Documents\My Videos.

    CSIDL_COMPUTERSNEARME (FOLDERID_NetworkFolder)
        The folder that represents other computers in your workgroup.

    CSIDL_CONNECTIONS (FOLDERID_ConnectionsFolder)
        The virtual folder that represents Network Connections, that contains network and dial-up connections.

    CSIDL_CONTROLS (FOLDERID_ControlPanelFolder)
        The virtual folder that contains icons for the Control Panel applications.

    CSIDL_COOKIES (FOLDERID_Cookies)
        The file system directory that serves as a common repository for Internet cookies. A typical path is C:\Documents and Settings\username\Cookies.

    CSIDL_DESKTOP (FOLDERID_Desktop)
        The virtual folder that represents the Windows desktop, the root of the namespace.

    CSIDL_DESKTOPDIRECTORY (FOLDERID_Desktop)
        The file system directory used to physically store file objects on the desktop (not to be confused with the desktop folder itself). A typical path is C:\Documents and Settings\username\Desktop.

    CSIDL_DRIVES (FOLDERID_ComputerFolder)
        The virtual folder that represents My Computer, containing everything on the local computer: storage devices, printers, and Control Panel. The folder can also contain mapped network drives.

    CSIDL_FAVORITES (FOLDERID_Favorites)
        The file system directory that serves as a common repository for the user's favorite items. A typical path is C:\Documents and Settings\username\Favorites.

    CSIDL_FONTS (FOLDERID_Fonts)
        A virtual folder that contains fonts. A typical path is C:\Windows\Fonts.

    CSIDL_HISTORY (FOLDERID_History)
        The file system directory that serves as a common repository for Internet history items.

    CSIDL_INTERNET (FOLDERID_InternetFolder)
        A virtual folder for Internet Explorer. 

    CSIDL_INTERNET_CACHE (FOLDERID_InternetCache)
        Version 4.72. The file system directory that serves as a common repository for temporary Internet files. A typical path is C:\Documents and Settings\username\Local Settings\Temporary Internet Files.

    CSIDL_LOCAL_APPDATA (FOLDERID_LocalAppData)
        Version 5.0. The file system directory that serves as a data repository for local (nonroaming) applications. A typical path is C:\Documents and Settings\username\Local Settings\Application Data.

    CSIDL_MYDOCUMENTS (FOLDERID_Documents)
        Version 6.0. The virtual folder that represents the My Documents desktop item. This value is equivalent to CSIDL_PERSONAL.

    CSIDL_MYMUSIC (FOLDERID_Music)
        The file system directory that serves as a common repository for music files. A typical path is C:\Documents and Settings\User\My Documents\My Music.

    CSIDL_MYPICTURES (FOLDERID_Pictures)
        Version 5.0. The file system directory that serves as a common repository for image files. A typical path is C:\Documents and Settings\username\My Documents\My Pictures.

    CSIDL_MYVIDEO (FOLDERID_Videos)
        Version 6.0. The file system directory that serves as a common repository for video files. A typical path is C:\Documents and Settings\username\My Documents\My Videos.

    CSIDL_NETHOOD (FOLDERID_NetHood)
        A file system directory that contains the link objects that may exist in the My Network Places virtual folder. It is not the same as CSIDL_NETWORK, which represents the network namespace root. A typical path is C:\Documents and Settings\username\NetHood.

    CSIDL_NETWORK (FOLDERID_NetworkFolder)
        A virtual folder that represents Network Neighborhood, the root of the network namespace hierarchy.

    CSIDL_PERSONAL (FOLDERID_Documents)
        Version 6.0. The virtual folder that represents the My Documents desktop item. This is equivalent to CSIDL_MYDOCUMENTS.

        Previous to Version 6.0. The file system directory used to physically store a user's common repository of documents. A typical path is C:\Documents and Settings\username\My Documents. This should be distinguished from the virtual My Documents folder in the namespace. To access that virtual folder, use SHGetFolderLocation, which returns the ITEMIDLIST for the virtual location, or refer to the technique described in Managing the File System.

    CSIDL_PRINTERS (FOLDERID_PrintersFolder)
        The virtual folder that contains installed printers.

    CSIDL_PRINTHOOD (FOLDERID_PrintHood)
        The file system directory that contains the link objects that can exist in the Printers virtual folder. A typical path is C:\Documents and Settings\username\PrintHood.

    CSIDL_PROFILE (FOLDERID_Profile)
        Version 5.0. The user's profile folder. A typical path is C:\Documents and Settings\username. Applications should not create files or folders at this level; they should put their data under the locations referred to by CSIDL_APPDATA or CSIDL_LOCAL_APPDATA.

    CSIDL_PROGRAM_FILES (FOLDERID_ProgramFiles)
        Version 5.0. The Program Files folder. A typical path is C:\Program Files.

    CSIDL_PROGRAM_FILESX86 (FOLDERID_ProgramFilesX86)

    CSIDL_PROGRAM_FILES_COMMON (FOLDERID_ProgramFilesCommon)
        Version 5.0. A folder for components that are shared across applications. A typical path is C:\Program Files\Common. Valid only for Windows NT, Windows 2000, and Windows XP systems. Not valid for Windows Millennium Edition (Windows Me).

    CSIDL_PROGRAM_FILES_COMMONX86 (FOLDERID_ProgramFilesCommonX86)

    CSIDL_PROGRAMS (FOLDERID_Programs)
        The file system directory that contains the user's program groups (which are themselves file system directories). A typical path is C:\Documents and Settings\username\Start Menu\Programs. 

    CSIDL_RECENT (FOLDERID_Recent)
        The file system directory that contains shortcuts to the user's most recently used documents. A typical path is C:\Documents and Settings\username\My Recent Documents. To create a shortcut in this folder, use SHAddToRecentDocs. In addition to creating the shortcut, this function updates the Shell's list of recent documents and adds the shortcut to the My Recent Documents submenu of the Start menu.

    CSIDL_RESOURCES (FOLDERID_ResourceDir)
        Windows Vista. The file system directory that contains resource data. A typical path is C:\Windows\Resources.

    CSIDL_RESOURCES_LOCALIZED (FOLDERID_LocalizedResourcesDir)

    CSIDL_SENDTO (FOLDERID_SendTo)
        The file system directory that contains Send To menu items. A typical path is C:\Documents and Settings\username\SendTo.

    CSIDL_STARTMENU (FOLDERID_StartMenu)
        The file system directory that contains Start menu items. A typical path is C:\Documents and Settings\username\Start Menu.

    CSIDL_STARTUP (FOLDERID_Startup)
        The file system directory that corresponds to the user's Startup program group. The system starts these programs whenever any user logs onto Windows NT or starts Windows 95. A typical path is C:\Documents and Settings\username\Start Menu\Programs\Startup.

    CSIDL_SYSTEM (FOLDERID_System)
        Version 5.0. The Windows System folder. A typical path is C:\Windows\System32.

    CSIDL_SYSTEMX86 (FOLDERID_SystemX86)

    CSIDL_TEMPLATES (FOLDERID_Templates)
        The file system directory that serves as a common repository for document templates. A typical path is C:\Documents and Settings\username\Templates.

    CSIDL_WINDOWS (FOLDERID_Windows)
        Version 5.0. The Windows directory or SYSROOT. This corresponds to the %windir% or %SYSTEMROOT% environment variables. A typical path is C:\Windows.

    Flags 

    CSIDL_FLAG_CREATE (KF_FLAG_CREATE)
        Version 5.0. Combine with another CSIDL to force the creation of the associated folder if it does not exist.

    CSIDL_FLAG_DONT_UNEXPAND (KF_FLAG_DONT_UNEXPAND)
        Combine with another CSIDL constant to ensure the expansion of environment variables.

    CSIDL_FLAG_DONT_VERIFY (KF_FLAG_DONT_VERIFY)
        Combine with another CSIDL constant, except for CSIDL_FLAG_CREATE, to return an unverified folder path with no attempt to create or initialize the folder.

    CSIDL_FLAG_NO_ALIAS (KF_FLAG_NO_ALIAS)
        Combine with another CSIDL constant to ensure the retrieval of the true system path for the folder, free of any aliased placeholders such as %USERPROFILE%, returned by SHGetFolderLocation. This flag has no effect on paths returned by SHGetFolderPath.

    CSIDL_FLAG_PER_USER_INIT 

    CSIDL_FLAG_MASK 
        A mask for any valid CSIDL flag value.

Remarks

    These values supersede the use of environment variables for this purpose. They are in turn superseded in Windows Vista and later by the KNOWNFOLDERID values.

    A CSIDL is used in conjunction with one of four Shell functions, SHGetFolderLocation, SHGetFolderPath, SHGetSpecialFolderLocation, and SHGetSpecialFolderPath, to retrieve a special folder's path or pointer to an item identifier list (PIDL).

    Combine CSIDL_FLAG_CREATE with any of the other CSIDLs, except for CSIDL_FLAG_DONT_VERIFY, to force the creation of the associated folder. The remaining CSIDLs correspond to either file system folders or virtual folders. Where the CSIDL identifies a file system folder, a commonly used path is given as an example. Other paths may be used. Some CSIDLs can be mapped to an equivalent %VariableName% environment variable. CSIDLs are more reliable, however, and should be used if possible.
**/
