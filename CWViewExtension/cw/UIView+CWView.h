//
//  UIView+CWView.h
//  CWViewExtension
//
//  Created by 罗泰 on 2019/12/6.
//  Copyright © 2019 罗泰. All rights reserved.
//
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (CWView)
#pragma mark - copy from YYKit begin
#pragma mark - copy from YYKit begin
#pragma mark - copy from YYKit begin
/**
 Create a snapshot image of the complete view hierarchy.
 */
- (nullable UIImage *)cw_snapshotImage;

/**
 Create a snapshot image of the complete view hierarchy.
 @discussion It's faster than "snapshotImage", but may cause screen updates.
 See -[UIView drawViewHierarchyInRect:afterScreenUpdates:] for more information.
 */
- (nullable UIImage *)cw_snapshotImageAfterScreenUpdates:(BOOL)afterUpdates;

/**
 Create a snapshot PDF of the complete view hierarchy.
 */
- (nullable NSData *)cw_snapshotPDF;

/**
 Shortcut to set the view.layer's shadow
 
 @param color  Shadow Color
 @param offset Shadow offset
 @param radius Shadow radius
 */
- (void)cw_setLayerShadow:(nullable UIColor*)color offset:(CGSize)offset radius:(CGFloat)radius opacity:(CGFloat)opacity;

/**
 Remove all subviews.
 
 @warning Never call this method inside your view's drawRect: method.
 */
- (void)cw_removeAllSubviews;

/**
 Returns the view's view controller (may be nil).
 */
@property (nullable, nonatomic, readonly) UIViewController *cw_viewController;

/**
 Returns the visible alpha on screen, taking into account superview and window.
 */
@property (nonatomic, readonly) CGFloat cw_visibleAlpha;

/**
 Converts a point from the receiver's coordinate system to that of the specified view or window.
 
 @param point A point specified in the local coordinate system (bounds) of the receiver.
 @param view  The view or window into whose coordinate system point is to be converted.
    If view is nil, this method instead converts to window base coordinates.
 @return The point converted to the coordinate system of view.
 */
- (CGPoint)cw_convertPoint:(CGPoint)point toViewOrWindow:(nullable UIView *)view;

/**
 Converts a point from the coordinate system of a given view or window to that of the receiver.
 
 @param point A point specified in the local coordinate system (bounds) of view.
 @param view  The view or window with point in its coordinate system.
    If view is nil, this method instead converts from window base coordinates.
 @return The point converted to the local coordinate system (bounds) of the receiver.
 */
- (CGPoint)cw_convertPoint:(CGPoint)point fromViewOrWindow:(nullable UIView *)view;

/**
 Converts a rectangle from the receiver's coordinate system to that of another view or window.
 
 @param rect A rectangle specified in the local coordinate system (bounds) of the receiver.
 @param view The view or window that is the target of the conversion operation. If view is nil, this method instead converts to window base coordinates.
 @return The converted rectangle.
 */
- (CGRect)cw_convertRect:(CGRect)rect toViewOrWindow:(nullable UIView *)view;

/**
 Converts a rectangle from the coordinate system of another view or window to that of the receiver.
 
 @param rect A rectangle specified in the local coordinate system (bounds) of view.
 @param view The view or window with rect in its coordinate system.
    If view is nil, this method instead converts from window base coordinates.
 @return The converted rectangle.
 */
- (CGRect)cw_convertRect:(CGRect)rect fromViewOrWindow:(nullable UIView *)view;


@property (nonatomic) CGFloat cw_left;        ///< Shortcut for frame.origin.x.
@property (nonatomic) CGFloat cw_top;         ///< Shortcut for frame.origin.y
@property (nonatomic) CGFloat cw_right;       ///< Shortcut for frame.origin.x + frame.size.width
@property (nonatomic) CGFloat cw_bottom;      ///< Shortcut for frame.origin.y + frame.size.height
@property (nonatomic) CGFloat cw_width;       ///< Shortcut for frame.size.width.
@property (nonatomic) CGFloat cw_height;      ///< Shortcut for frame.size.height.
@property (nonatomic) CGFloat cw_centerX;     ///< Shortcut for center.x
@property (nonatomic) CGFloat cw_centerY;     ///< Shortcut for center.y
@property (nonatomic) CGPoint cw_origin;      ///< Shortcut for frame.origin.
@property (nonatomic) CGSize  cw_size;        ///< Shortcut for frame.size.
#pragma mark - copy from YYKit end
#pragma mark - copy from YYKit end
#pragma mark - copy from YYKit end


#pragma mark - chenwang
/**
 设置角标,角标为0时会消失.如果为0时不想消失,请自行修改源码
 默认超过99条时候显示为99+
 */
@property (nonatomic, assign) NSInteger               badge;
/**
 角标label 默认宽高28.
 自定义宽高请修改cw_size即可.
 */
@property (nonatomic, strong, readonly) UILabel       *badgeLabel;
@end

NS_ASSUME_NONNULL_END
