//
//  WaypointController.h
//  Pocket Gnome
//
//  Created by Jon Drummond on 12/16/07.
//  Copyright 2007 Savory Software, LLC. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "SaveData.h"

@class Route;
@class RouteSet;
@class Waypoint;
@class Controller;
@class PlayerDataController;
@class BotController;

@class BetterTableView;
@class PTHotKey;
@class SRRecorderControl;

@class BetterSegmentedControl;
@class RouteVisualizationView;

@interface WaypointController : SaveData {

    IBOutlet Controller *controller;
    IBOutlet PlayerDataController *playerData;
    IBOutlet id mobController;
    IBOutlet BotController *botController;
    IBOutlet id movementController;
    IBOutlet id combatController;

    IBOutlet BetterTableView *waypointTable;
    
    IBOutlet NSView *view;
    IBOutlet RouteVisualizationView *visualizeView;
    IBOutlet NSPanel *visualizePanel;
    IBOutlet NSMenu *actionMenu;
    IBOutlet NSMenu *testingMenu;
    IBOutlet NSPanel *renamePanel;
    
    // waypoint action editor
    IBOutlet NSPanel *wpActionPanel;
    IBOutlet NSTabView *wpActionTabs;
    IBOutlet NSTextField *wpActionDelayText;
    IBOutlet BetterSegmentedControl *wpActionTypeSegments;
    IBOutlet NSPopUpButton *wpActionIDPopUp;
    Waypoint *_editWaypoint;
	
    // waypoint recording
    IBOutlet NSButton *automatorStartStopButton;
    IBOutlet NSPanel *automatorPanel;
    IBOutlet NSTextField *automatorIntervalValue;
    IBOutlet NSProgressIndicator *automatorSpinner;
    IBOutlet RouteVisualizationView *automatorVizualizer;
    
    IBOutlet SRRecorderControl *shortcutRecorder;
	IBOutlet SRRecorderControl *automatorRecorder;
    
    IBOutlet id routeTypeSegment;
    RouteSet *_currentRouteSet;
	Route *_currentRoute;
    PTHotKey *addWaypointGlobalHotkey;
	PTHotKey *automatorGlobalHotkey;
    NSMutableArray *_routes;
    BOOL validSelection, validWaypointCount;
	BOOL isAutomatorRunning, disableGrowl;
    NSSize minSectionSize, maxSectionSize;
	
	IBOutlet NSPanel *descriptionPanel;
	NSString *_descriptionMultiRows;
	NSIndexSet *_selectedRows;
	
	NSString *_nameBeforeRename;
	
	IBOutlet NSButton		*scrollWithRoute;
	IBOutlet NSTextField	*waypointSectionTitle;
}

- (void)saveRoutes;

- (NSArray*)routes;
@property (readonly) NSView *view;
@property (readonly) NSString *sectionTitle;
@property NSSize minSectionSize;
@property NSSize maxSectionSize;

@property BOOL validSelection;
@property BOOL validWaypointCount;
@property BOOL isAutomatorRunning;
@property BOOL disableGrowl;
@property (readonly) Route *currentRoute;
@property (readwrite, retain) RouteSet *currentRouteSet;
@property (readwrite, retain) NSString *descriptionMultiRows;

// route actions
- (IBAction)setRouteType: (id)sender;
- (IBAction)createRoute: (id)sender;
- (IBAction)loadRoute: (id)sender;
- (IBAction)removeRoute: (id)sender;
- (IBAction)renameRoute: (id)sender;
- (IBAction)closeRename: (id)sender;
- (IBAction)duplicateRoute: (id)sender;
- (IBAction)waypointMenuAction: (id)sender;
- (IBAction)closeDescription: (id)sender;
- (IBAction)showInFinder: (id)sender;

// importing/exporting
- (void)importRouteAtPath: (NSString*)path;
- (IBAction)importRoute: (id)sender;
- (IBAction)exportRoute: (id)sender;

- (IBAction)visualize: (id)sender;
- (IBAction)closeVisualize: (id)sender;
- (IBAction)moveToWaypoint: (id)sender;
- (IBAction)testWaypointSequence: (id)sender;
- (IBAction)stopMovement: (id)sender;
- (IBAction)closestWaypoint: (id)sender;

// waypoint automation
- (IBAction)openAutomatorPanel: (id)sender;
- (IBAction)closeAutomatorPanel: (id)sender;
- (IBAction)startStopAutomator: (id)sender;
- (IBAction)resetAllWaypoints: (id)sender;

// waypoint actions
- (IBAction)addWaypoint: (id)sender;
- (IBAction)removeWaypoint: (id)sender;
- (IBAction)editWaypointAction: (id)sender;
- (void)waypointActionEditorClosed: (BOOL)change;

// new action/conditions
- (void)selectCurrentWaypoint:(int)index;

@end
