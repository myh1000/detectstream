/*
 * Google Chrome.h
 */

#import <AppKit/AppKit.h>
#import <ScriptingBridge/ScriptingBridge.h>


@class GoogleChromeApplication, GoogleChromeWindow, GoogleChromeTab, GoogleChromeBookmarkFolder, GoogleChromeBookmarkItem;

/*
 * Standard Suite
 */

// The application's top-level scripting object.
@interface GoogleChromeApplication : SBApplication
+ (GoogleChromeApplication *) application;

- (SBElementArray<GoogleChromeWindow *> *) windows;

@property (copy, readonly) NSString *name;  // The name of the application.
@property (readonly) BOOL frontmost;  // Is this the frontmost (active) application?
@property (copy, readonly) NSString *version;  // The version of the application.

- (void) open:(NSArray<NSURL *> *)x;  // Open a document.
- (void) quit;  // Quit the application.
- (BOOL) exists:(id)x;  // Verify if an object exists.

@end

// A window.
@interface GoogleChromeWindow : SBObject

- (SBElementArray<GoogleChromeTab *> *) tabs;

@property (copy, readonly) NSString *name;  // The full title of the window.
- (NSInteger) id;  // The unique identifier of the window.
@property NSInteger index;  // The index of the window, ordered front to back.
@property NSRect bounds;  // The bounding rectangle of the window.
@property (readonly) BOOL closeable;  // Whether the window has a close box.
@property (readonly) BOOL minimizable;  // Whether the window can be minimized.
@property BOOL minimized;  // Whether the window is currently minimized.
@property (readonly) BOOL resizable;  // Whether the window can be resized.
@property BOOL visible;  // Whether the window is currently visible.
@property (readonly) BOOL zoomable;  // Whether the window can be zoomed.
@property BOOL zoomed;  // Whether the window is currently zoomed.
@property (copy, readonly) GoogleChromeTab *activeTab;  // Returns the currently selected tab
@property (copy) NSString *mode;  // Represents the mode of the window which can be 'normal' or 'incognito', can be set only once during creation of the window.
@property NSInteger activeTabIndex;  // The index of the active tab.


@end



/*
 * Chromium Suite
 */

// The application's top-level scripting object.
@interface GoogleChromeApplication (ChromiumSuite)

- (SBElementArray<GoogleChromeBookmarkFolder *> *) bookmarkFolders;

@property (copy, readonly) GoogleChromeBookmarkFolder *bookmarksBar;  // The bookmarks bar bookmark folder.
@property (copy, readonly) GoogleChromeBookmarkFolder *otherBookmarks;  // The other bookmarks bookmark folder.

@end

// A tab.
@interface GoogleChromeTab : SBObject

- (NSInteger) id;  // Unique ID of the tab.
@property (copy, readonly) NSString *title;  // The title of the tab.
@property (copy) NSString *URL;  // The url visible to the user.
@property (readonly) BOOL loading;  // Is loading?


@end

// A bookmarks folder that contains other bookmarks folder and bookmark items.
@interface GoogleChromeBookmarkFolder : SBObject

- (SBElementArray<GoogleChromeBookmarkFolder *> *) bookmarkFolders;
- (SBElementArray<GoogleChromeBookmarkItem *> *) bookmarkItems;

- (NSNumber *) id;  // Unique ID of the bookmark folder.
@property (copy) NSString *title;  // The title of the folder.
@property (copy, readonly) NSNumber *index;  // Returns the index with respect to its parent bookmark folder


@end

// An item consists of an URL and the title of a bookmark
@interface GoogleChromeBookmarkItem : SBObject

- (NSInteger) id;  // Unique ID of the bookmark item.
@property (copy) NSString *title;  // The title of the bookmark item.
@property (copy) NSString *URL;  // The URL of the bookmark.
@property (copy, readonly) NSNumber *index;  // Returns the index with respect to its parent bookmark folder


@end

@interface GoogleChromeWindow (ChromiumSuite)

@property (readonly) BOOL presenting;  // Whether the window is in presentation mode.

@end

