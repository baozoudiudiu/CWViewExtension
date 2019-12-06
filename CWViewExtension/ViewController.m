//
//  ViewController.m
//  CWViewExtension
//
//  Created by 罗泰 on 2019/12/6.
//  Copyright © 2019 罗泰. All rights reserved.
//

#import "ViewController.h"
#import "UIView+CWView.h"

@interface ViewController ()
/// 调试视图
@property (nonatomic, strong) UIView    *testView;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.testView = [[UIView alloc] initWithFrame:CGRectZero];
    self.testView.translatesAutoresizingMaskIntoConstraints = NO;
    self.testView.backgroundColor = UIColor.grayColor;
    
    [self.view addSubview:self.testView];
    NSDictionary *dic = NSDictionaryOfVariableBindings(_testView);
    [self.view addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:[_testView(==100)]" options:kNilOptions metrics:nil views:dic]];
    [self.view addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:[_testView(==240)]" options:kNilOptions metrics:nil views:dic]];
    NSLayoutConstraint *vlc = [NSLayoutConstraint constraintWithItem:self.testView attribute:NSLayoutAttributeCenterY relatedBy:NSLayoutRelationEqual toItem:self.view attribute:NSLayoutAttributeCenterY multiplier:1 constant:0];
    NSLayoutConstraint *hlc = [NSLayoutConstraint constraintWithItem:self.testView attribute:NSLayoutAttributeCenterX relatedBy:NSLayoutRelationEqual toItem:self.view attribute:NSLayoutAttributeCenterX multiplier:1 constant:0];
    [self.view addConstraints:@[vlc, hlc]];
    
    
//    [self.testView cw_setLayerShadow:UIColor.grayColor offset:CGSizeMake(0, 0) radius:4.0 opacity:0.5];
    
    
}

- (void)viewDidLayoutSubviews {
    [super viewDidLayoutSubviews];
    self.testView.badge = 100;
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    self.testView.badge = 0;
    
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(3 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        self.testView.badge = 8;
    });
}
@end
